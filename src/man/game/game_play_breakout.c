#include <man/game/game.h>
#include <pong/man/game/game.h>

void _game_playBreakout(void) {
    TRoom *room = man_rooms_setCurrentRoom(ROOM_ID_BREAKOUT);

    man_rooms_setExplored(room);

    sys_render_clearRoom(_game_action);
    _render_updateRoom(room);

    breakout_man_game_init();
    breakout_man_game_start();
}