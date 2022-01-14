#include "entity.h"

TEntity* _man_entity_calculateNextFree() {
    TEntity *entity = m_man_entity_nextFree + 1;
    u8 index = m_man_entity_nextFreeIndex + 1;
    u8 count = MAN_ENTITY_BUFFER_SIZE;

    while (count > 0) {
        if (index == MAN_ENTITY_BUFFER_SIZE) {
            index = 0;
            entity = m_man_entity_buffer;
        }

        if (entity->state == ENTITY_STATE_INVALID) {
            m_man_entity_nextFreeIndex = index;
            m_man_entity_nextFree = entity;
            return;
        }

        ++index;
        ++entity;
        --count;
    }

    sys_debug_info("MAN_ENTITY ERROR: MAX ENTITIES REACHED!", 0, 0);
}

TEntity* man_entity_create(void) {
    TEntity *entity = m_man_entity_nextFree;
    // ++m_man_entity_reservedEntities;
    ++m_man_entity_validEntities;

    _man_entity_calculateNextFree();

    return entity;
}