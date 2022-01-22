#include "entity.h"

// [E1][E2][f][.]
TEntity* cme_create(void) {
    TEntity *entity = m_cme_nextFree;
    ++m_cme_nextFree;
    ++m_cme_validEntities;
    return entity;
}