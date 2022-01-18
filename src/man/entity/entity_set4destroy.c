#include "entity.h"

void man_entity_set4destroy(TEntity* entity) {
    entity->state |= ENTITY_STATE_DEAD;
    m_man_entity_isDirty = 1;
}
