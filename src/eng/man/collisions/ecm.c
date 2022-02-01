#include "ecm.h"

TECM_collision  m_ecm_buffer[ECM_MAX_COLLISIONS]; // collisions buffer
TECM_collision* m_ecm_next_free;                  // ptr to the next free entity
u8              m_ecm_num;                        // num collisions stored