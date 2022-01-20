#include "entity.h"

void man_entity_forAll(TEntityCallback callback) {
    TEntity *entity = m_man_entity_buffer;
    while(entity->state != ENTITY_STATE_INVALID) {
        callback(entity);
        ++entity;
    }
}