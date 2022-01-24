#include <pong/sys/ai/ai.h>

void m_pong_sys_ai_updateOne(TEEM_entity *e) {
    if (e->ai) {
        e->ai(e);
    }
}

void pong_sys_ai_update() {
    eem_for_all(m_pong_sys_ai_updateOne);
}