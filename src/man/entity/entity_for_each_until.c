#include "entity.h"

void man_entity_forEachUntil(TEntityUntilCallback callback) {
    TEntity *entity = m_man_entity_buffer;
    u8 count = m_man_entity_validEntities;
    while(count > 0) {
        if (entity->state != ENTITY_STATE_INVALID) {
            u8 result = callback(entity);
            if (result != 0) {
                return;
            }
            --count;
        }
        ++entity;
    }
}