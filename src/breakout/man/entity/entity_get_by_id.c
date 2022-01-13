#include <breakout/man/entity/entity.h>

TBreakoutEntity *breakout_man_entity_getById(TBreakoutEntityId id) {
    TBreakoutEntity *entity = _breakout_man_entity_buffer;
    while (entity->id != BREAKOUT_ENTITY_ID_NULL) {
        if (entity->id == id) {
            return entity;
        }
        ++entity;
    };
    return 0;
}