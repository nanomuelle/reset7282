#include <breakout/man/game/game.h>
#include <breakout/sys/render/render.h>

void breakout_man_game_render(void) {
    cpct_waitVSYNCStart();

    ers_update();
    eem_update();

    // // csa_update();   // anim system
    // csr_update();   // render system

    // // finally do remove dead entities
    // man_entity_update();
}