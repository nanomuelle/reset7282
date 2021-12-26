#include <man/game/game.h>

void man_game_input(void) {
    TRoom *room = man_rooms_getCurrentRoom();
    room->inputReader();
}
