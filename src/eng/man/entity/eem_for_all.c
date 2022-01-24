#include "eem.h"

void eem_for_all(TEEM_callback callback) {
    TEEM_entity *e = m_eem_buffer;
    while(e->state != EEM_STATE_INVALID) {
        callback(e);
        ++e;
    }
}

void eem_for_all_reversed(TEEM_callback callback) {
    TEEM_entity *e = m_eem_next_free - 1;
    while(e >= m_eem_buffer) {
        if (e->state != EEM_STATE_INVALID) {
            callback(e);
        }
        --e;
    }
}