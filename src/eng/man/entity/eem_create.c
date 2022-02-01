#include "eem.h"

// [E1][E2][f][.]
TEEM_entity* eem_create(void) {
    TEEM_entity *e = m_eem_next_free;
    m_eem_next_free = e + 1;
    ++m_eem_num_valid_entities;
    eem_set_state_redraw(e);
    return e;
}