#include "eps.h"

void eps_add_entity(TEEM_entity *e) {
    TEEM_entity **next_free = m_eps_next_free_entity;
    (*next_free) = e;
    ++next_free;
    m_eps_next_free_entity = next_free;
}

extern void eps_remove_entity(TEEM_entity *e) {
    // TODO
}
