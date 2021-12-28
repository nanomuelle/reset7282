#include <pong/man/entity/entity.h>

TPongEntity * pong_man_entity_getById(TPongEntityId id) {
    TPongEntity *entity = _pong_man_entity_buffer;
    while (entity->id != id) ++entity;
    return entity;
}