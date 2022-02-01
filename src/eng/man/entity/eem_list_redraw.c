#include "eem.h"

TEEM_redraw_entity   m_eem_redraw_buffer[EEM_BUFFER_SIZE];
TEEM_redraw_entity*  m_eem_redraw_next_free;
u8                   m_eem_redraw_num;

void eem_resetRedraw(void) {
    m_eem_redraw_next_free = m_eem_redraw_buffer; // ptr to the next free redraw entity
    m_eem_redraw_num = 0; // num redraw entities stored
}

TEEM_redraw_entity* eem_createRedraw(void) {
    TEEM_redraw_entity* re = m_eem_redraw_next_free;
    m_eem_redraw_next_free = re + 1;
    ++m_eem_redraw_num;
    return re;
}

void eem_forEachRedraw(TEEM_redrawCallback callback) {
    TEEM_redraw_entity* re = m_eem_redraw_next_free;
    while(re > m_eem_redraw_buffer) {
        --re;
        callback(re);
    }
}

void eem_set_state_redraw(TEEM_entity* e) {
    u8 state = e->state;

    // if it is already setted as redraw, or it is dead, nothing to do
    if ((state & EEM_STATE_REDRAW) || (state & EEM_STATE_DEAD)) {
        return;
    }

    {
        TEEM_redraw_entity* re = eem_createRedraw();
        re->e = e;
        e->state |= EEM_STATE_REDRAW;
    }
}