#include <pong/man/game/game.h>

#include <sys/render/render.h>

void m_pong_man_game_render_updateNet() {
    u8 color = cpct_px2byteM1(0, PONG_PEN, PONG_PEN, 0);
    u8 *pmem = cpct_getScreenPtr(
        CPCT_VMEM_START,
        CSR_WORLD_TO_SCREEN_X(0),
        CSR_WORLD_TO_SCREEN_Y(CSP_WORLD_MIN_Y)
    );
    cpct_drawSolidBox(pmem, color, 1, CSR_PHY_TO_PX(CSP_WORLD_H) - 2);
}

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
    m_pong_man_game_render_updateNet();
    m_pong_man_game_render_updateScore();

    csr_update();
}