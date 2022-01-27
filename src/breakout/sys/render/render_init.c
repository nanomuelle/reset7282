#include <breakout/sys/render/render.h>
#include <sys/render/render.h>
#include <breakout/breakout.h>
#include <assets/breakout_bg.h>

void m_breakout_sys_render_bg() {
    for (i16 y = 0; y < ERS_SCREEN_H; y += G_SPR_BRK_BG_0_H) {
        for (i16 x = 0; x < ERS_SCREEN_W; x += ERS_BYTES_TO_PX(G_SPR_BRK_BG_0_W)) {
            u8* bg = (cpct_rand8() > 127) ? g_spr_brk_bg_1 : g_spr_brk_bg_0;
            u8* pmem = ers_get_screen_ptr(x, y);
            cpct_drawSprite(bg, pmem, G_SPR_BRK_BG_0_W, G_SPR_BRK_BG_0_H);
        }
    }
}

void breakout_sys_render_init(void) {
    m_breakout_sys_render_bg();
    eem_for_all(ers_capture_one_bg);
    // eem_for_all(ers_update_one);
    // cme_forAll(csr_capture_one_bg);
}