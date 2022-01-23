#include "render.h"
#include <sys/render/render.h>

void m_csr_restore_one(TEntity* e) {
    if (e->state & (CME_ENTITY_STATE_MOVED | CME_ENTITY_STATE_DEAD)) {
        csr_restore_bg_one(e);
    }
}

void csr_update(void) {
    cme_forAllReversed(m_csr_restore_one);
    cme_forAll(csr_update_one);
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