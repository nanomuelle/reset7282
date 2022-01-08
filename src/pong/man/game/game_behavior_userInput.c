#include <pong/man/game/game.h>
#include <pong/sys/ai/ai.h>

void pong_man_game_behavior_userInput(void *me) {
    i16 vy = 0;
    if (cpct_isKeyPressed(Key_Q)) {
        vy = -PONG_WORLD_PADDEL_VY;
    } else if (cpct_isKeyPressed(Key_A)) {
        vy = PONG_WORLD_PADDEL_VY;
    }

    ((TPongEntity *) me)->vy = vy;
}