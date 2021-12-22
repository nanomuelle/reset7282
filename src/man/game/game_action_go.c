#include <cpctelera.h>

#include <man/rooms/rooms.h>
#include <man/history/history.h>
#include <man/rooms/rooms.h>
#include <man/msg/msg.h>

#include <sys/action/action.h>

typedef struct {
    u8 *description;
} TDirDescription;

const TDirDescription _dirDescriptions[5] = {
    {" n"}, {" s"}, {" e"}, {" o"}, {" ?"}
};

void _game_action_go(TAction* action, TRoom* room) {
    TParamGoEnum dir = action->param1.go_param;
    u8 roomIndex;

    man_msg_clear();
    man_msg_concat(sys_action_getActionName(action));
    man_history_addInfo(
        man_msg_concat(_dirDescriptions[dir].description)
    );

    if (dir == ACTION_PARAM_GO_UNKNOWN) {
        man_history_addWarning(" ->ir hacia donde?");
        return;
    }


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