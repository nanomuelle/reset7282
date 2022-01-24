#include <pong/man/game/game.h>
#include <pong/sys/ai/ai.h>

void pong_man_game_behavior_followBall(void *me) {
    TEEM_entity *target = eem_get_by_id(PONG_ENTITY_ID_BALL);
    pong_sys_ai_follow(me, target);
}