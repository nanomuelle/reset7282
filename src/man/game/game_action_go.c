#include <cpctelera.h>

#include <man/rooms/rooms.h>
#include <man/history/history.h>
#include <man/rooms/rooms.h>
#include <man/msg/msg.h>

#include <sys/parser/parser.h>

void _game_action_go(TAction* action, TRoom* room) {
    TParamGoEnum dir = action->param1.go_param;
    u8 roomId;

    if (dir == ACTION_PARAM_GO_UNKNOWN) {
        man_history_addResponse("ir hacia donde?");
        return;
    }

    roomId = room->outs.direction[dir];
    if (roomId == NO_EXIT) {
        man_history_addResponse("por ahi no hay salida");
        return;
    }

    man_rooms_setCurrentRoom(roomId);
}