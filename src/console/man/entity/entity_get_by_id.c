#include "entity.h"

TEntity *cme_getById(TEntityId id) {
    TEntity *entity = m_cme_buffer;
    while (entity->id != id) {
        ++entity;
    };

    return entity;
}