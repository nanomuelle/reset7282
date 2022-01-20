#include "entity.h"

void cme_init(void) {
    TEntity *entity = m_cme_buffer;

    m_cme_nextFree = entity;
    cpct_memset(entity, 0, sizeof(m_cme_buffer));
    m_cme_validEntities = 0;
}