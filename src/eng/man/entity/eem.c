#include "eem.h"

TEEM_entity  m_eem_buffer[EEM_BUFFER_SIZE];
TEEM_state   m_eem_buffer_eof;         // marca de final del buffer
u8           m_eem_num_valid_entities; // num of valid entities
TEEM_entity* m_eem_next_free;          // ptr to the next free entity
u8           m_eem_needs_update;       // flag: 1.- needs update, 0.- do not needs update

