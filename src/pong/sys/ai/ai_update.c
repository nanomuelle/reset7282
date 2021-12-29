#include <pong/sys/ai/ai.h>

void _pong_sys_ai_updateOne(TPongEntity *entity) {
    if (entity->ai) {
        entity->ai(entity);
    }
}

#define AI_DELAY 10

void pong_sys_ai_update() {
    static u8 delay = AI_DELAY;

    if (delay == 0) {
        delay = AI_DELAY;
        pong_man_entity_forEach(_pong_sys_ai_updateOne);
    }
    delay--;
}