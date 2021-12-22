#include <cpctelera.h>

#include <man/rooms/rooms.h>
#include <man/history/history.h>
#include <man/msg/msg.h>

#include <sys/parser/parser.h>
#include <sys/str/str.h>

#include <sys/debug/debug.h>

void _game_action_turn_on(TAction* action, TRoom* room) {
    TParamTurnOnEnum param = action->param1.turn_on_param;

    if (param == ACTION_PARAM_TURN_ON_UNKNOWN) {
        man_history_addError(" -> no se como encender eso");
        return;
    }
    
    if (room->id == ROOM_ID_INITIAL && param == ACTION_PARAM_TURN_ON_LIGHT) {
        man_msg_clear();
        man_history_addWarning(
            man_msg_concat(" -> ...y la luz se hizo")
        );

        man_rooms_setCurrentRoom(ROOM_ID_DORMITORIO_1);
    }
}