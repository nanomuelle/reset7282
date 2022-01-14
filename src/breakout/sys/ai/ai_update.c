#include <breakout/sys/ai/ai.h>
#include <man/entity/entity.h>

void _breakout_sys_ai_updateOne(TEntity *entity) {
    if (entity->ai) {
        entity->ai(entity);
    }
}

void breakout_sys_ai_update() {
    man_entity_forAll(_breakout_sys_ai_updateOne);
}