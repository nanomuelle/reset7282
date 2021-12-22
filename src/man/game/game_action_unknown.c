#include <cpctelera.h>

#include <man/rooms/rooms.h>
#include <man/history/history.h>

#include <sys/parser/parser.h>

void _game_action_unknown(TAction* action, TRoom* room) {
    man_history_addError("ERROR: comando desconocido");
}