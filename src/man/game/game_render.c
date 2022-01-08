#include <man/game/game.h>

void man_game_render() {
    TRoom* room = man_rooms_getCurrentRoom();
    cpct_waitVSYNC();
    room->gameHandlers->render();
}
