#include "entity.h"

TEntity  m_cme_buffer[CME_BUFFER_SIZE];
u8       m_cme_buffer_eof;
// u8       m_man_entity_reservedEntities;
u8       m_cme_validEntities;
TEntity* m_cme_nextFree;
u8       m_cme_nextFreeIndex;
u8       m_cme_isDirty;
