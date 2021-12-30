#include <cpctelera.h>

#include <man/rooms/rooms.h>
#include <man/history/history.h>
#include <man/rooms/rooms.h>
#include <man/msg/msg.h>

#include <sys/parser/parser.h>

const u8* const ACTION_GO_MSG[] = {
    "ir hacia donde?",
    "por ahi no hay salida",
    "tropiezas y caes",
};

void _game_action_go(TAction* action, TRoom* room) {
    TParamGoEnum dir = action->param1.go_param;
    u8 gotoRoomId = room->outs.direction[dir];
    u8 *msg = 0;

    if (dir == ACTION_PARAM_GO_UNKNOWN) {
        msg = ACTION_GO_MSG[0];
    } else if (gotoRoomId == NO_EXIT) {
        msg = ACTION_GO_MSG[1];
    } else if (man_rooms_isDark(room)) {
        msg = ACTION_GO_MSG[2];
    }

    if (msg != 0) {
        man_history_addResponse(msg);
    } else {
        man_rooms_setCurrentRoom(gotoRoomId);
    }
}