#include <cpctelera.h>

#include <man/game/game.h>
#include <man/history/history.h>

const u8* const ACTION_USE_MSGS[] = {
    "no se como usar eso",
    "no tengo acceso a ese objeto",
    "no puedo usar eso",
};

void _game_action_use(TAction* action, TRoom* room) {
    u8* msg = 0;

    // objeto desconocido ?
    if (action->param1.obj_param == OBJ_ID_NULL) {
        msg = ACTION_USE_MSGS[0];
    } else {
        // esta en esta habitación o en el inventario
        TObj *obj = man_objs_getObj(action->param1.obj_param);
        if ( obj->roomId != room->id && obj->roomId != ROOM_ID_INVENTARIO) {
            msg = ACTION_USE_MSGS[1];
        } else if ( (obj->attrs & OBJ_ATTR_CAN_USE) != OBJ_ATTR_CAN_USE ) {
            // es un objeto que puede ser usado
            // TODO incluir en el msg en nombre del objeto que no puedo usar
            msg = ACTION_USE_MSGS[2];
        }
    }

    // si hay msg de error se muestra y salimos
    if (msg != 0x00) {
        man_history_addError(msg);
        return;
    }

    if (action->param1.obj_param == OBJ_ID_LIGHT) {
        _game_action_turn_on(action, room);
        return;
    }

    if (action->param1.obj_param == OBJ_ID_CONSOLA) {
        _game_playPong();
        return;
    }
}