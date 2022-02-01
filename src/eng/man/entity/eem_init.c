#include "eem.h"

void eem_init(void) {
    TEEM_entity *e = m_eem_buffer;
    m_eem_next_free = e;
    cpct_memset(e, 0, sizeof(m_eem_buffer));
    m_eem_num_valid_entities = 0;
    m_eem_buffer_eof = EEM_STATE_INVALID;

    eem_resetDead();
    eem_resetMoved();
    eem_resetRedraw();
}