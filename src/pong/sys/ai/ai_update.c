#include <pong/sys/ai/ai.h>

void _pong_sys_ai_updateOne(TPongEntity *entity) {
    if (entity->ai) {
        entity->ai(entity);
    }
}

void pong_sys_ai_update() {
    pong_man_entity_forEach(_pong_sys_ai_updateOne);
}