#include <cpctelera.h>

#include <man/game/game.h>
#include <man/history/history.h>
#include <man/objs/objs.h>

#include <sys/parser/parser.h>

u8 _game_takeObjFromRoom(TObjEnum objId, TRoomIdEnum roomId ) {
    // Si el objeto no esta en la habitacion, no lo podemos coger
    if (!man_objs_isInRoom(objId, roomId)) {
        return 1;
    }

    man_objs_moveToRoom(objId, ROOM_ID_INVENTARIO);
    return 0;
}

void _game_action_take(TAction* action, TRoom* room) {
    TObjEnum objId;

    if (action->param1.take_param == ACTION_PARAM_TAKE_UNKNOWN) {
        man_history_addError("coger el que?");
    }
    
    switch(action->param1.take_param) {
        case ACTION_PARAM_TAKE_RAQUETA:
            objId = OBJ_ID_RAQUETA;
        break;
    }

    if (_game_takeObjFromRoom(objId, room->id)) {
        TRoom* inventario = man_rooms_getRoom(ROOM_ID_INVENTARIO);
        man_history_addResponse("objeto recogido");
        _game_show_objs_in_room(inventario);
    } else {
        man_history_addResponse("ese objeto no esta aqui");
    }
}