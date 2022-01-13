#include <breakout/man/entity/entity.h>

void breakout_man_entity_init(void) {
    _breakout_man_entity_numEntities = 0;
    cpct_memset(_breakout_man_entity_buffer, 0, BREAKOUT_MAN_ENTITY_BUFFER_SIZE * sizeof(TBreakoutEntity));
}