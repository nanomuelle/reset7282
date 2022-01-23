#include "ers.h"
#include <sys/render/render.h>

void m_ers_restore_one(TEEM_entity* e) {
    if (e->state & (EEM_STATE_MOVED | EEM_STATE_DEAD)) {
        // ers_restore_bg_one(e);
        u8* sprite_bg = e->render.sprite_bg;
        u8 w = e->render.w;
        u8 h = e->render.h;
        u8* pmem = e->render.pmem;

        cpct_drawSprite(sprite_bg, pmem, w, h);
    }
}

void ers_update(void) {
    eem_forAllReversed(m_ers_restore_one);
    eem_forAll(ers_update_one);
}

// // ;; HL = screen address
// // ;; DE = pointer to array of sprite data
// // ;; A = pixel offset in sprite
// // ;; B = height
// // ;; C = width
// u8* param1;
// u8* param2;
// u8  param3;
// u8  param4;
// u8  param5;
// void csr_pp_pipo(u8* pmem, u8 *sprite, u16 shift, u8 w, u8 h) __z88dk_callee {
//     param1 = pmem;
//     param2 = sprite;
//     param3 = shift;
//     param4 = w;
//     param5 = h;
// }