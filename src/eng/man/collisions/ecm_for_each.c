#include "ecm.h"

void ecm_forEach(TECM_callback callback) {
    TECM_collision* collision = m_ecm_next_free;

    while(collision > m_ecm_buffer) {
        --collision;
        callback(collision);
    }
}