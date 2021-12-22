#include <cpctelera.h>

#include <man/rooms/rooms.h>
#include <man/history/history.h>

#include <sys/action/action.h>

void _game_action_search(TAction* action, TRoom* room) {
    man_history_addInfo("buscar");
    man_history_addWarning(" -> no encuentras nada");
}