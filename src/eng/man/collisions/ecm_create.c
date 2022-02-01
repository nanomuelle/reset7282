#include "ecm.h"

TECM_collision* ecm_create(void) {
    TECM_collision* c = m_ecm_next_free;
    m_ecm_next_free = c + 1;
    ++m_ecm_num;
    return c;
}