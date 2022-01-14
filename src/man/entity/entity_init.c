#include "entity.h"

void man_entity_init(void) {
    TEntity *entity = m_man_entity_buffer;

    m_man_entity_nextFree = entity;
    cpct_memset(entity, 0, sizeof(m_man_entity_buffer));
    // m_man_entity_reservedEntities = 0;
    m_man_entity_validEntities = 0;
    m_man_entity_nextFreeIndex = 0;
    m_man_entity_isDirty = 0;
}