#include <cpctelera.h>

#include <man/game/game.h>
#include <man/history/history.h>
#include <man/objs/objs.h>

#include <sys/parser/parser.h>

const u8* NULL_STRING = "";

const THistoryMsg const ACTION_EXAMINE_MSG[3] = {
    { HISTORY_TYPE_ERROR, "\xAEExaminar el que?" },
    { HISTORY_TYPE_ERROR, "no veo eso por aqui" },
    { HISTORY_TYPE_RESPONSE, (u8* const) 0x00 }
};

void _game_action_examine(TAction* action, TRoom* room) {
    THistoryMsg *msg;
    u8 isObjInRoom;
    u8 isObjInInventory;

    // objeto desconocido
    if (action->param1.obj_param == OBJ_ID_NULL) {
        man_history_addMsg(&ACTION_EXAMINE_MSG[0]);
        return;
    }

    isObjInRoom = man_objs_isInRoom(action->param1.obj_param, room->id);
    isObjInInventory = man_objs_isInRoom(action->param1.obj_param, ROOM_ID_INVENTARIO);

    // el objeto no esta en la habitación ni en el inventario
    // o el objeto esta en la habitación, pero la habitación no esta explorada
    if ( (!isObjInRoom && !isObjInInventory) || 
         (isObjInRoom && !man_rooms_isExplored(room)) ) {
        man_history_addMsg(&ACTION_EXAMINE_MSG[1]);
        return;
    }

    {
        TObj *obj = man_objs_getObj(action->param1.obj_param);
        msg = &ACTION_EXAMINE_MSG[2];
        msg->txt = obj->description;
        man_history_addMsg(msg);
    }
}