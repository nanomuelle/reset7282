#include "entity.h"

void cme_forAll(TEntityCallback callback) {
    TEntity *entity = m_cme_buffer;
    while(entity->state != CME_ENTITY_STATE_INVALID) {
        callback(entity);
        ++entity;
    }
}