#include <breakout/man/entity/entity.h>

void breakout_man_entity_forEach(TBreakoutEntityCallback entityCallback) {
    TBreakoutEntity *entity = _breakout_man_entity_buffer;
    for (u8 i = 0; i < _breakout_man_entity_numEntities; ++i, ++entity) {
        entityCallback(entity);
    }
}