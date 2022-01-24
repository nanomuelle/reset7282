#ifndef PONG_SYS_AI
#define PONG_SYS_AI

#include <pong/pong.h>

// PUBLIC
extern void pong_sys_ai_init();
extern void pong_sys_ai_update();
extern void pong_sys_ai_follow(TEEM_entity *me, TEEM_entity *target);
#endif