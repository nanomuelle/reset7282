#include "entity.h"

void man_entity_destroy(TEntity* entity) {
    TEntity *last = m_man_entity_nextFree - 1;
    if (entity != last) {
        cpct_memcpy(entity, last, sizeof(TEntity));
    }
    last->state = ENTITY_STATE_INVALID;
    m_man_entity_nextFree = last;
    --m_man_entity_validEntities;
}
