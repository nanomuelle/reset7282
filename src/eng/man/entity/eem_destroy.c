#include "eem.h"

// FROM
//          v
// [E1][E2][E3][E4][E5[f][.]
//
// TO
// [E1][E2][E5][E4][f][.][.]
//
void eem_destroy(TEEM_entity* e) {
    TEEM_entity *last = m_eem_next_free - 1;
    if (e != last) {
        cpct_memcpy(e, last, sizeof(TEEM_entity));
    }
    last->state = EEM_STATE_INVALID;
    m_eem_next_free = last;
    --m_eem_num_valid_entities;
}
