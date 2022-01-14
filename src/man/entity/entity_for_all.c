#include "entity.h"

void man_entity_forAll(TEntityCallback callback) {
    TEntity *entity = m_man_entity_buffer;
    u8 count = m_man_entity_validEntities;
    while(count > 0) {
        if (entity->state != ENTITY_STATE_INVALID) {
            callback(entity);
            --count;
        }
        ++entity;
    }
}