#include <cpctelera.h>

#include <man/game/game.h>
#include <man/history/history.h>
#include <man/objs/objs.h>

#include <sys/parser/parser.h>

void _game_action_take(TAction* action, TRoom* room) {
    TObj *obj;

    if (action->param1.take_param == ACTION_PARAM_TAKE_UNKNOWN) {
        man_history_addWarning("coger el que?");
    }

    switch(action->param1.take_param) {
        case ACTION_PARAM_TAKE_RAQUETA:
            obj = man_objs_getObj(OBJ_ID_RAQUETA);
        break;
    }

    if (obj->roomId == room->id) {
        obj->roomId = ROOM_ID_INVENTARIO;
        man_history_addWarning("-> objeto recogido");
        _game_show_objs_in_room(ROOM_ID_INVENTARIO);
    } else {
        man_history_addWarning("-> ese objeto no esta aqui");
    }
}