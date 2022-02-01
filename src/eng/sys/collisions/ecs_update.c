#include "ecs.h"

void m_ecm_update_pair(TEEM_entity* e1, TEEM_entity* e2) {
    if (ecs_check_pair(e1, e2)) {
        TECM_collision* collision = ecm_create();
        collision->e1 = e1;
        collision->e2 = e2;
    }
}

void ecs_update(void) {
    ecm_reset();
    eem_for_pairs(
        m_ecm_update_pair, 
        EEM_STATE_MOVED | EEM_STATE_SOLID | EEM_STATE_VALID, 
        EEM_STATE_SOLID | EEM_STATE_VALID
    );
}

// 
// [B][P][E1][E2][E3]
// 