#ifndef PONG_SYS_AI
#define PONG_SYS_AI

#include <pong/man/entity/entity.h>

// PUBLIC
extern void pong_sys_ai_init();
extern void pong_sys_ai_update();
extern void pong_sys_ai_follow(TPongEntity *me, TPongEntity *target);
#endif