#include <cpctelera.h>

#include <man/rooms/rooms.h>
#include <man/history/history.h>

#include <sys/parser/parser.h>
#include <sys/str/str.h>

void _game_action_turn_on(TAction* action, TRoom* room) {
    if (action->param1.obj_param == OBJ_ID_NULL) {
        man_history_addError("no se como encender eso");
        return;
    }

    if (action->param1.obj_param == OBJ_ID_LIGHT) {
        man_history_addResponse("y la luz se hizo");

        if (room->id == ROOM_ID_INITIAL) {
            man_rooms_setCurrentRoom(ROOM_ID_DORMITORIO_1);
        }
    }
}