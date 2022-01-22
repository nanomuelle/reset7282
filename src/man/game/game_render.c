#include <man/game/game.h>

void man_game_render() {
    TRoom* room = man_rooms_getCurrentRoom();
    room->gameHandlers->render();
}
