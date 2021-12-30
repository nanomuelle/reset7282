#include <man/game/game.h>
#include <pong/man/game/game.h>

void _game_playPong(void) {
    TRoom *room = man_rooms_setCurrentRoom(ROOM_ID_PONG);
    if (!man_rooms_isExplored(room)) {
        man_rooms_setExplored(room);
    }

    sys_render_clearRoom(_game_action);
    _render_updateRoom(room);

    pong_man_game_init();
    pong_man_game_start();
}