#include "entity.h"

TEntity  m_man_entity_buffer[MAN_ENTITY_BUFFER_SIZE];
// u8       m_man_entity_reservedEntities;
u8       m_man_entity_validEntities;
TEntity* m_man_entity_nextFree;
u8       m_man_entity_nextFreeIndex;
u8       m_man_entity_isDirty;
