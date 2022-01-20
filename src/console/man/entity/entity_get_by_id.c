#include "entity.h"

TEntity *man_entity_getById(TEntityId id) {
    TEntity *entity = m_man_entity_buffer;
    while (entity->id != id) {
        ++entity;
    };

    return entity;
}