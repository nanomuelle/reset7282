#include <cpctelera.h>

#include <man/rooms/rooms.h>
#include <man/history/history.h>
#include <man/rooms/rooms.h>
#include <man/msg/msg.h>

#include <sys/action/action.h>

typedef struct {
    u8 *description;
} TDirDescription;

const TDirDescription _dirDescriptions[4] = {
    {" n"}, {" s"}, {" e"}, {" o"}
};

void _game_action_go(TAction* action, TRoom* room) {
    TRoomDirectionsEnum dir = action->param1;
    u8 roomIndex;

    man_msg_clear();
    man_msg_concat(sys_action_getActionName(action));

    if (dir == DIR_UNKNOWN) {
        man_history_addInfo("ir ?");
        man_history_addWarning(" ->ir hacia donde?");
        return;
    }

    man_history_addInfo(
        man_msg_concat(_dirDescriptions[action->param1].description)
    );

    roomIndex = room->outs.direction[dir];
    if (roomIndex == NO_EXIT) {
        man_history_addWarning(" -> por ahi no hay salida");
        return;
    }

    {
        TRoom *room = man_rooms_setCurrentRoom(roomIndex);

        man_msg_clear();
        man_msg_concat(" -> ");
        man_history_addWarning(
            man_msg_concat(room->name)
        );
    }
}