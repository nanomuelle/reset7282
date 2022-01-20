#include "entity.h"

void man_entity_update(void) {
    if (m_cme_isDirty) {
        TEntity *entity = m_cme_buffer;
        while (entity->state != CME_ENTITY_STATE_INVALID) {
            if (entity->state & CME_ENTITY_STATE_DEAD) {
                cme_destroy(entity);
            } else {
                ++entity;
            }
        }
        m_cme_isDirty = 0;
    }
}