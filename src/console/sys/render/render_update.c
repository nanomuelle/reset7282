#include "render.h"
#include <sys/render/render.h>

void m_csr_restore_one(TEntity* e) {
    if (e->state & (CME_ENTITY_STATE_MOVED | CME_ENTITY_STATE_DEAD)) {
        csr_restore_bg_one(e);
    }
}

void csr_update(void) {
    cme_forAllReversed(m_csr_restore_one);
    // sys_debug_info("fondo listo");
    // cpct_waitVSYNC();
    cme_forAll(csr_update_one);
    // sys_debug_info("render listo");
}