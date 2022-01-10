#include <cpctelera.h>

#include <man/game/game.h>
#include <man/history/history.h>
#include <man/objs/objs.h>

#include <sys/parser/parser.h>

const u8* const ACTION_DROP_MSG[] = {
    "\xAEdejar el que?",
    "no puedo soltar algo que no tengo",
    "no puedo dejar eso",
    "esta habitacion esta llena",
    "objeto soltado"
};

void _game_action_drop(TAction* action, TRoom* room) {
    TObj *obj;
    
    if (action->param1.obj_param == OBJ_ID_NULL) {
        man_history_addError(ACTION_DROP_MSG[0]);
        return;
    }

    obj = man_objs_getObj(action->param1.obj_param);

    // Si no está en el inventario, no puedo soltarlo
    if (obj->roomId != ROOM_ID_INVENTARIO) {
        man_history_addError(ACTION_DROP_MSG[1]);
        return;
    }

    // Si no se puede coger, no se puede soltar
    if ( (obj->attrs & OBJ_ATTR_CAN_TAKE) != OBJ_ATTR_CAN_TAKE ) {
        man_history_addError(ACTION_DROP_MSG[2]);
        return;
    }

    // Si no caben mas cosas en la habitacion, no se puede soltar
    if (man_objs_getNumObjsInRoom(room->id) == MAX_OBJS_IN_ROOM) {
        man_history_addError(ACTION_DROP_MSG[3]);
        return;
    }

    // Objeto soltado
    man_objs_moveToRoom(obj->id, room->id);
    man_history_addResponse(ACTION_DROP_MSG[4]);
}