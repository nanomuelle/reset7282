#include "entity.h"

void cme_destroy(TEntity* entity) {
    TEntity *last = m_cme_nextFree - 1;
    if (entity != last) {
        cpct_memcpy(entity, last, sizeof(TEntity));
    }
    last->state = CME_ENTITY_STATE_INVALID;
    m_cme_nextFree = last;
    --m_cme_validEntities;
}
