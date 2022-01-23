#include "eem.h"

void eem_update(void) {
    if (m_eem_needs_update) {
        TEEM_entity *e = m_eem_buffer;
        while (e->state != EEM_STATE_INVALID) {
            if (e->state & EEM_STATE_DEAD) {
                eem_destroy(e);
            } else {
                ++e;
            }
        }
        m_eem_needs_update = 0;
    }
}