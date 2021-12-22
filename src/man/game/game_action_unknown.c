#include <cpctelera.h>
#include <sys/action/action.h>
#include <man/rooms/rooms.h>

#include <sys/debug/debug.h>

void _game_action_unknown(TAction* action, TRoom* room) {
    sys_debug_info("runner_unknown", 0, 190);
    sys_debug_waitKey();
}