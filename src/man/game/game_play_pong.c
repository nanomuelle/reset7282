#include <man/game/game.h>
#include <pong/man/game/game.h>

void _game_playPong(void) {
    TRoom *room = man_rooms_setCurrentRoom(ROOM_ID_PONG);
    if (!room->explored) {
        pong_man_game_init();
        room->explored = EXPLORED;
    }
    
    sys_render_clearRoom(_game_action);
    _render_updateRoom(room);
    
    pong_man_game_start();
}