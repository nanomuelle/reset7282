#include <breakout/man/game/game.h>
#include <breakout/sys/render/render.h>

void breakout_man_game_render(void) {
    csa_update();
    csr_update();

    // finally do remove dead entities
    man_entity_update();
}