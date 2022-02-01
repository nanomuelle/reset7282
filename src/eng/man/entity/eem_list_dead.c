#include "eem.h"

TEEM_dead_entity    m_eem_dead_buffer[EEM_BUFFER_SIZE];
TEEM_dead_entity*   m_eem_dead_next_free;
u8                   m_eem_dead_num;

void eem_resetDead(void) {
    m_eem_dead_next_free = m_eem_dead_buffer; // ptr to the next free dead entity
    m_eem_dead_num = 0; // num dead entities stored
}

void eem_forEachDead(TEEM_deadCallback callback) {
    TEEM_dead_entity* me = m_eem_dead_next_free;

    while(me > m_eem_dead_buffer) {
        --me;
        callback(me);
    }
}

TEEM_dead_entity* eem_createDead(void) {
    TEEM_dead_entity* me = m_eem_dead_next_free;
    m_eem_dead_next_free = me + 1;
    ++m_eem_dead_num;
    return me;
}

void eem_set_state_dead(TEEM_entity* e) {
    // if it is already setted as dead, nothing to do
    if (e->state & EEM_STATE_DEAD) {
        return;
    }

    {
        TEEM_dead_entity* me = eem_createDead();
        me->e = e;
        e->state |= EEM_STATE_DEAD;
    }
}