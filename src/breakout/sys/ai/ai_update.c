#include <breakout/sys/ai/ai.h>

void _breakout_sys_ai_updateOne(TEEM_entity *e) {
    if (e->ai) {
        e->ai(e);
    }
}

void breakout_sys_ai_update() {
    eem_for_all(_breakout_sys_ai_updateOne);
}