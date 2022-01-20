#include "entity.h"

// TEntity* _man_entity_calculateNextFree() {
//     TEntity *entity = m_cme_nextFree + 1;
//     u8 index = m_cme_nextFreeIndex + 1;
//     u8 count = CME_BUFFER_SIZE;

//     while (count > 0) {
//         if (index == CME_BUFFER_SIZE) {
//             index = 0;
//             entity = m_cme_buffer;
//         }

//         if (entity->state == CME_ENTITY_STATE_INVALID) {
//             m_cme_nextFreeIndex = index;
//             m_cme_nextFree = entity;
//             return;
//         }

//         ++index;
//         ++entity;
//         --count;
//     }

//     sys_debug_info("MAN_ENTITY ERROR: MAX ENTITIES REACHED!", 0, 0);
// }

// [E1][E2][f][.]
TEntity* cme_create(void) {
    TEntity *entity = m_cme_nextFree;
    ++m_cme_nextFree;
    ++m_cme_validEntities;

//    _man_entity_calculateNextFree();

    return entity;
}