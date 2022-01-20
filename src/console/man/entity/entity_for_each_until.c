#include "entity.h"

void cme_forEachUntil(TEntityUntilCallback callback) {
    TEntity *entity = m_cme_buffer;
    while(entity->state != CME_ENTITY_STATE_INVALID) {
        u8 result = callback(entity);
        if (result != 0) {
            return;
        }
        ++entity;
    }
}