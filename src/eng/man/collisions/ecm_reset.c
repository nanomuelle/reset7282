#include "ecm.h"

void ecm_reset(void) {
    m_ecm_next_free = m_ecm_buffer; // ptr to the next free entity
    m_ecm_num = 0; // num collisions stored    
}