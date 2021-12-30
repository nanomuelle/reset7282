#include <man/game/game.h>
#include <man/rooms/rooms.h>

void man_game_new(void) {
    man_game_init();
    man_rooms_setCurrentRoom(ROOM_ID_DORMITORIO_1);

    _game_action = 0x00;
}
