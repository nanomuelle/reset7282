#include <breakout/sys/ai/ai.h>

void _breakout_sys_ai_updateOne(TEntity *entity) {
    if (entity->ai) {
        entity->ai(entity);
    }
}

void breakout_sys_ai_update() {
    cme_forAll(_breakout_sys_ai_updateOne);
}