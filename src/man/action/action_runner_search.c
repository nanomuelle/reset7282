#include <cpctelera.h>
#include <man/action/action.h>
#include <man/rooms/rooms.h>

#include <sys/debug/debug.h>

void man_action_runner_search(TAction* action, TRoom* room) {
    sys_debug_infoString("man_action_runner_search (any key to continue)", 0, 50);
    sys_debug_waitKey();
}