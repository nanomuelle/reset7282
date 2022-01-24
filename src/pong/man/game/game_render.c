#include <pong/man/game/game.h>

// #include <sys/render/render.h>

#include <assets/pong_ball_m1.h>

void m_pong_man_game_render_updateScore() {
    // csr_printChar(
    //     48 + pong_man_score_getLeftPlayer(),
    //     CSR_WORLD_TO_SCREEN_X( (CSP_WORLD_W / 2) - CSP_PX_TO_WORLD(32) ),
    //     CSR_WORLD_TO_SCREEN_Y( CSP_WORLD_MIN_Y + CSP_PX_TO_WORLD(2) ),
    //     PONG_PEN
    // );

    // csr_printChar(
    //     48 + pong_man_score_getRightPlayer(),
    //     CSR_WORLD_TO_SCREEN_X( (CSP_WORLD_W / 2) + CSP_PX_TO_WORLD(32 - 4) ),
    //     CSR_WORLD_TO_SCREEN_Y( CSP_WORLD_MIN_Y + CSP_PX_TO_WORLD(2) ),
    //     PONG_PEN
    // );
}

void pong_man_game_render(void) {
    m_pong_man_game_render_updateScore();
    cpct_waitVSYNCStart();
    ers_update();
}