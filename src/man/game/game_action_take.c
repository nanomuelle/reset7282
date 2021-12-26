#include <cpctelera.h>

#include <man/game/game.h>
#include <man/history/history.h>
#include <man/objs/objs.h>

#include <sys/parser/parser.h>

u8 _game_takeObjFromRoom(TObjEnum objId, TRoomIdEnum roomId ) {
    // Si el objeto no esta en la habitacion, no lo podemos coger
    if (!man_objs_isInRoom(objId, roomId)) {
        return 0;
    }

    man_objs_moveToRoom(objId, ROOM_ID_INVENTARIO);
    return 1;
}

void _game_action_take(TAction* action, TRoom* room) {
    if (action->param1.obj_param == OBJ_ID_NULL) {
        man_history_addError("coger el que?");
        return;
    }

    {
        TObj *obj = man_objs_getObj(action->param1.obj_param);
        if ( (obj->attrs & OBJ_ATTR_CAN_TAKE) != OBJ_ATTR_CAN_TAKE ) {
            man_history_addError("no puedo coger eso");
            return;
        }
    }

    if (_game_takeObjFromRoom(action->param1.obj_param, room->id)) {
        TRoom* inventario = man_rooms_getRoom(ROOM_ID_INVENTARIO);
        man_history_addResponse("objeto recogido");
        _game_show_objs_in_room(inventario);
    } else {
        man_history_addResponse("ese objeto no esta aqui");
    }
}