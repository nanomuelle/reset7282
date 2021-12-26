#include <cpctelera.h>

#include <man/game/game.h>
#include <man/history/history.h>

const u8* const ACTION_USE_MSGS[] = {
    "no se como usar eso",
    "no puedo usar eso"
};

void _game_action_use(TAction* action, TRoom* room) {
    if (action->param1.obj_param == OBJ_ID_NULL) {
        man_history_addError(ACTION_USE_MSGS[0]);
        return;
    }

    {
        TObj *obj = man_objs_getObj(action->param1.obj_param);
        if ( (obj->attrs & OBJ_ATTR_CAN_USE) != OBJ_ATTR_CAN_USE ) {
            // TODO incluir en el msg en nombre del objeto que no puedo usar
            man_history_addError(ACTION_USE_MSGS[1]);
            return;
        }
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