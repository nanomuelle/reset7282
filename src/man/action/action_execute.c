#include <man/action/action.h>
#include <sys/debug/debug.h>

typedef void (*TActionRunner)(TAction*, TRoom*);

const TActionRunner actionRunners[] = {
    man_action_runner_go,
    man_action_runner_search,
    man_action_runner_unknown
};

void man_action_execute(TAction* action, TRoom *room) {
    TActionRunner actionRunner = actionRunners[action->type];

    sys_debug_infoString("action: ", 0, 50);
    sys_debug_infoString(man_action_getActionName(action), 0, 60);
    sys_debug_infoChar(48 + action->type, 0, 70);
    sys_debug_waitKey();

    actionRunner(action, room);

    // if (action->type == ACTION_GO) {
    //     TRoomDirectionsEnum direction = action->param1;
    //     if (direction == DIR_UNKNOWN) {
    //         return;
    //     }
    //     man_action_execute_go(room, direction);
    // }
}