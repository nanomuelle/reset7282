#include "entity.h"

void man_entity_forEachUntil(TEntityUntilCallback callback) {
    TEntity *entity = m_man_entity_buffer;
    while(entity->state != ENTITY_STATE_INVALID) {
        u8 result = callback(entity);
        if (result != 0) {
            return;
        }
        ++entity;
    }
}