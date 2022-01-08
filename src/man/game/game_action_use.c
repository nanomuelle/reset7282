#include <types.h>

#include <man/game/game.h>
#include <man/history/history.h>

const u8* const ACTION_USE_MSGS[] = {
    "no se como usar eso",
    "no tengo acceso a ese objeto",
    "no veo nada"
};

void _game_action_use(TAction* action, TRoom* room) {
    TObj *obj = man_objs_getObj(action->param1.obj_param);

    // objeto desconocido ?
    if (action->param1.obj_param == OBJ_ID_NULL) {
        man_history_addError(ACTION_USE_MSGS[0]);
        return;
    }

    // objeto luz ?
    if (action->param1.obj_param == OBJ_ID_LIGHT) {
        _game_action_turn_on(action, room);
        return;
    }

    // esta en esta habitación ?
    if (obj->roomId == room->id) {
        // sin luz
        if (man_rooms_isDark(room)) {
            man_history_addError(ACTION_USE_MSGS[2]);
            return;
        }

        // sin explorar ?
        if (!man_rooms_isExplored(room)) {
            man_history_addError(ACTION_USE_MSGS[1]);
            return;
        }

        // se puede usar ?
        if ( (obj->attrs & OBJ_ATTR_CAN_USE != OBJ_ATTR_CAN_USE) ) {
            man_history_addError(ACTION_USE_MSGS[0]);
            return;
        }
    }

    // tengo el objeto en el inventario ?
    if (obj->roomId == ROOM_ID_INVENTARIO) {
        // se puede usar ?
        if ( (obj->attrs & OBJ_ATTR_CAN_USE != OBJ_ATTR_CAN_USE) ) {
            man_history_addError(ACTION_USE_MSGS[0]);
            return;
        }
    }

    if (action->param1.obj_param == OBJ_ID_CONSOLA) {
        _game_playPong();
        return;
    }
}