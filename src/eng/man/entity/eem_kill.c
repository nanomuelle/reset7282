#include "eem.h"

void eem_kill(TEEM_entity* e) {
    e->state |= EEM_STATE_DEAD;
    m_eem_needs_update = 1;
}
