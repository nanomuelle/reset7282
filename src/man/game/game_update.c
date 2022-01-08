#include <man/game/game.h>

void man_game_update(void) {
    TRoom *room = man_rooms_getCurrentRoom();
    room->gameHandlers->update();
}