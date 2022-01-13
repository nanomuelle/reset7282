#include <breakout/man/game/game.h>
#include <breakout/sys/ai/ai.h>

void breakout_man_game_update(void) {
    // TPongEntity *ball = pong_man_entity_getById(PONG_ENTITY_ID_BALL);

    // _checkGameOver();

    breakout_sys_ai_update();
    breakout_sys_physics_update();

    // _checkLeftPaddelCollision(ball);
    // _checkRightPaddelCollision(ball);
    // _checkScore(ball);
}