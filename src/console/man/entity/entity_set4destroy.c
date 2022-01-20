#include "entity.h"

void cme_set4destroy(TEntity* entity) {
    entity->state |= CME_ENTITY_STATE_DEAD;
    m_cme_isDirty = 1;
}
