#include <cpctelera.h>

#include <man/game/game.h>
#include <man/history/history.h>

void _game_action_use(TAction* action, TRoom* room) {
    if (action->param1.obj_param == OBJ_ID_NULL) {
        man_history_addError("no se como usar eso");
        return;
    }

    {
        TObj *obj = man_objs_getObj(action->param1.obj_param);
        if ( (obj->attrs & OBJ_ATTR_CAN_USE) != OBJ_ATTR_CAN_USE ) {
            // TODO incluir en el msg en nombre del objeto que no puedo usar
            man_history_addError("no puedo usar eso");
            return;
        }
    }

    if (action->param1.obj_param == OBJ_ID_LIGHT) {
        _game_action_turn_on(action, room);
    }
}