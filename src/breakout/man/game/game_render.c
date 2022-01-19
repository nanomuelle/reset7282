#include <breakout/man/game/game.h>
#include <breakout/sys/render/render.h>

void breakout_man_game_render(void) {
    breakout_sys_render_update();
    man_entity_update();
}