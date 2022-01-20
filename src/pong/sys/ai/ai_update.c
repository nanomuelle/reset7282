#include <pong/sys/ai/ai.h>

void m_pong_sys_ai_updateOne(TEntity *entity) {
    if (entity->ai) {
        entity->ai(entity);
    }
}

void pong_sys_ai_update() {
    cme_forAll(m_pong_sys_ai_updateOne);
}