#include "entity.h"
//    0   1  2   3  4  5   6
//   [E1][-][E2][-][-][E3][-]
//    ^


void _man_entity_update_one(void) {
    TEntity *entity = m_man_entity_buffer;
    u8 count = m_man_entity_validEntities;
    TEntity *freeEntity;

    while (count > 0) {
        if (entity->state == ENTITY_STATE_INVALID) {
            TEntity *nextEntity = entity + 1;
            // todo: posible improve, only copy if nextEntity is valid
            cpct_memcpy(entity, nextEntity, sizeof(TEntity));
            nextEntity->state = ENTITY_STATE_INVALID;
            return;
        } else {
            --count;
        }
        ++entity;
    }

    m_man_entity_isDirty = 0;
}

//
// cada ejecución de update, intercambia como mucho una posición
//
void man_entity_update(void) {
    if (m_man_entity_isDirty != 0) {
        return;
    }

    _man_entity_update_one();
}