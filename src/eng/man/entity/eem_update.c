#include "eem.h"

void m_eem_update_reset_moved_one(TEEM_moved_entity* me) {
    me->e->state &= EEM_STATE_MOVED_MASK;
}

void m_eem_update_reset_redraw_one(TEEM_redraw_entity* me) {
    me->e->state &= EEM_STATE_REDRAW_MASK;
}

void eem_update(void) {
    // reset moved and redraw states
    eem_forEachMoved(m_eem_update_reset_moved_one);
    eem_forEachRedraw(m_eem_update_reset_redraw_one);

    if (m_eem_dead_num > 0) {
        TEEM_entity *e = m_eem_buffer;
        while (e->state != EEM_STATE_INVALID) {
            if (e->state & EEM_STATE_DEAD) {
                eem_destroy(e);
            } else {
                ++e;
            }
        }
    }

    eem_resetRedraw();
    eem_resetMoved();
    eem_resetDead();
}