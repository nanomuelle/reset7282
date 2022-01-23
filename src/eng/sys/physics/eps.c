#include "eps.h"

TEEM_entity*  m_eps_entities[EPS_MAX_ENTITIES]; // one extra reserved pointer to mark last entity as always invalid
TEEM_entity*  m_eps_entities_eof;
TEEM_entity** m_eps_next_free_entity;