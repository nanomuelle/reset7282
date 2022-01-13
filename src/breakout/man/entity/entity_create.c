#include <breakout/man/entity/entity.h>

TBreakoutEntity *breakout_man_entity_create(void) {
    if (_breakout_man_entity_numEntities == BREAKOUT_MAN_ENTITY_BUFFER_SIZE) {
        sys_debug_info("BREAKOUT ERROR: MAX NUM OF ENTITIES REACHED!!!!", 0, 0);
        while(1);
        return;
    }

    {
        TBreakoutEntity *entity = &_breakout_man_entity_buffer[_breakout_man_entity_numEntities];
        ++_breakout_man_entity_numEntities;
        return entity;
    }
}