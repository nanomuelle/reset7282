#include "physics.h"

TEntity*  m_csp_entities[CSP_MAX_ENTITIES + 1]; // one extra reserved pointer to mark last entity as always invalid
TEntity** m_csp_next_free_entity;

void  csp_addEntity(TEntity *entity) {
    TEntity **next_free_entity = m_csp_next_free_entity;
    (*next_free_entity) = entity;
    ++next_free_entity;
    m_csp_next_free_entity = next_free_entity;
}

extern void  csp_removeEntity(TEntity *entity) {
    // TODO
}
