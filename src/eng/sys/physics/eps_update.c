#include "eps.h"

void eps_update(void) {
    TEEM_entity **e = m_eps_entities;

    while(*e != EPS_INVALID_ENTITY) {
        eps_update_one(*e);
        ++e;
    }
}