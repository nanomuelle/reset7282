#include "physics.h"

void csp_init(void) {
    cpct_memset(m_csp_entities, 0, sizeof(m_csp_entities));
    m_csp_next_free_entity = m_csp_entities;
}