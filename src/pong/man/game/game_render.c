#include <pong/man/game/game.h>

#include <sys/render/render.h>

void m_pong_man_game_render_updateScore() {
    _render_printChar(
        48 + pong_man_score_getLeftPlayer(),
        CSR_WORLD_TO_SCREEN_X(-(256 * 3)),
        CSR_WORLD_TO_SCREEN_Y(CSP_WORLD_MIN_Y + (256 * 2)),
        PONG_PEN
    );

    _render_printChar(
        48 + pong_man_score_getRightPlayer(),
        CSR_WORLD_TO_SCREEN_X(256 * (3 - 1)),
        CSR_WORLD_TO_SCREEN_Y(CSP_WORLD_MIN_Y + (256 * 2)),
        PONG_PEN
    );
}

void pong_man_game_render(void) {
    m_pong_man_game_render_updateScore();

    csr_update();
}