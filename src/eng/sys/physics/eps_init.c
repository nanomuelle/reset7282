#include "eps.h"

void eps_init(void) {
    cpct_memset(m_eps_entities, 0, sizeof(m_eps_entities));
    m_eps_next_free_entity = m_eps_entities;
    m_eps_entities_eof = EPS_INVALID_ENTITY;
}