#include <man/game/game.h>
#include <man/rooms/rooms.h>

void man_game_new(void) {
    man_game_init();
    man_rooms_setCurrentRoom(ROOM_INITIAL);
}