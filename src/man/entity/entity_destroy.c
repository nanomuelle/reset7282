#include "entity.h"

void man_entity_destroy(TEntity* entity) {
    entity->state = ENTITY_STATE_INVALID;
    --m_man_entity_validEntities;
    m_man_entity_isDirty = 1;
}
