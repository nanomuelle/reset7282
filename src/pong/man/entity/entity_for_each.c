#include <pong/man/entity/entity.h>

void pong_man_entity_forEach(TPongEntityCallback entityCallback) {
    TPongEntity *entity = _pong_man_entity_buffer;
    for (u8 i=0; i < _pong_man_entity_numEntities; ++i, ++entity) {
        entityCallback(entity);
    }
}