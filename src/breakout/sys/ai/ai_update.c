#include <breakout/sys/ai/ai.h>

void _breakout_sys_ai_updateOne(TBreakoutEntity *entity) {
    if (entity->ai) {
        entity->ai(entity);
    }
}

void breakout_sys_ai_update() {
    breakout_man_entity_forEach(_breakout_sys_ai_updateOne);
}