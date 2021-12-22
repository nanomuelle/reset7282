#include <cpctelera.h>
#include <sys/action/action.h>
#include <man/rooms/rooms.h>

#include <sys/debug/debug.h>

void _game_action_search(TAction* action, TRoom* room) {
    sys_debug_info("_game_action_search (any key)", 0, 190);
    sys_debug_waitKey();
}