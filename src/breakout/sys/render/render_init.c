#include <breakout/sys/render/render.h>
#include <sys/render/render.h>
#include <breakout/breakout.h>
#include <assets/breakout_bg.h>

void m_breakout_sys_render_bg() {
    u16 x, y;
    for (y = 0; y < ERS_SCREEN_H; y += G_SPR_BRK_BG_0_H) {
        for (x = 0; x < ERS_SCREEN_W; x += ERS_BYTES_TO_PX(G_SPR_BRK_BG_0_W)) {
            if (y == 0 && x > 0 && x < ERS_SCREEN_W - ERS_BYTES_TO_PX(G_SPR_BRK_BG_0_W)) {
                cpct_drawSprite(
                    g_spr_brk_bg_2, ers_get_screen_ptr(x, y), G_SPR_BRK_BG_0_W, G_SPR_BRK_BG_0_H
                );
            } else if (y > 0) {
                u8* bg = (cpct_rand8() > 127) ? g_spr_brk_bg_1 : g_spr_brk_bg_0;
                cpct_drawSprite(bg, ers_get_screen_ptr(x, y), G_SPR_BRK_BG_0_W, G_SPR_BRK_BG_0_H);
            }
        }
        if (y > 0) {
            cpct_drawSprite(
                g_spr_brk_bg_4, ers_get_screen_ptr(0, y), G_SPR_BRK_BG_0_W, G_SPR_BRK_BG_0_H
            );
            cpct_drawSprite(
                g_spr_brk_bg_5, 
                ers_get_screen_ptr(ERS_SCREEN_W - ERS_BYTES_TO_PX(G_SPR_BRK_BG_0_W), y),
                G_SPR_BRK_BG_0_W, G_SPR_BRK_BG_0_H
            );
        }
    }
    cpct_drawSprite(
        g_spr_brk_bg_3, ers_get_screen_ptr(0, 0), G_SPR_BRK_BG_0_W, G_SPR_BRK_BG_0_H
    );
    cpct_drawSpriteHFlipM1(
        g_spr_brk_bg_3,
        ers_get_screen_ptr(BRK_LIMIT_RIGHT - ERS_BYTES_TO_PX(G_SPR_BRK_BG_0_W), 0),
        G_SPR_BRK_BG_0_W, G_SPR_BRK_BG_0_H
    );
}

void breakout_sys_render_init(void) {
    m_breakout_sys_render_bg();
    eem_for_all(ers_capture_one_bg);
    // eem_for_all(ers_update_one);
    // cme_forAll(csr_capture_one_bg);
}