#include "entity.h"

void man_entity_update(void) {
    if (m_man_entity_isDirty) {
        TEntity *entity = m_man_entity_buffer;
        while (entity->state != ENTITY_STATE_INVALID) {
            if (entity->state & ENTITY_STATE_DEAD) {
                man_entity_destroy(entity);
            } else {
                ++entity;
            }
        }
        m_man_entity_isDirty = 0;
    }
}