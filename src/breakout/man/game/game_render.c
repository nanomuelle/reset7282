#include <breakout/man/game/game.h>
#include <breakout/sys/render/render.h>

void breakout_man_game_render(void) {
    // sys_debug_info("BREAKOUT!!!", 0, 0);
    breakout_sys_render_update();
}