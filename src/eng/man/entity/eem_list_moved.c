#include "eem.h"

TEEM_moved_entity    m_eem_moved_buffer[EEM_BUFFER_SIZE];
TEEM_moved_entity*   m_eem_moved_next_free;
u8                   m_eem_moved_num;

void eem_resetMoved(void) {
    m_eem_moved_next_free = m_eem_moved_buffer; // ptr to the next free moved entity
    m_eem_moved_num = 0; // num moved entities stored
}

void eem_forEachMoved(TEEM_movedCallback callback) {
    TEEM_moved_entity* me = m_eem_moved_next_free;

    while(me > m_eem_moved_buffer) {
        --me;
        callback(me);
    }
}

TEEM_moved_entity* eem_createMoved(void) {
    TEEM_moved_entity* me = m_eem_moved_next_free;
    m_eem_moved_next_free = me + 1;
    ++m_eem_moved_num;
    return me;
}

void eem_set_state_moved(TEEM_entity* e) {
    // if it is already setted as moved, nothing to do
    if (e->state & EEM_STATE_MOVED) {
        return;
    }

    {
        TEEM_moved_entity* me = eem_createMoved();
        me->e = e;
        e->state |= EEM_STATE_MOVED;
    }
}