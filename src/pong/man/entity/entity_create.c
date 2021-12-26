#include <pong/man/entity/entity.h>

TPongEntity _pong_man_entity_buffer[PONG_MAN_ENTITY_BUFFER_SIZE];
u8          _pong_man_entity_numEntities = 0;

TPongEntity *pong_man_entity_create(void) {
    TPongEntity *entity = &_pong_man_entity_buffer[_pong_man_entity_numEntities];
    ++_pong_man_entity_numEntities;
    return entity;
}