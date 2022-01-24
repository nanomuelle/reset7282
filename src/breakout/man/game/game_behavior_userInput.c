#include <breakout/man/game/game.h>
#include <breakout/sys/ai/ai.h>

void breakout_man_game_behavior_userInput(void *me) {
    i16 vx = 0;
    if (cpct_isKeyPressed(Key_O)) {
        vx = -BREAKOUT_WORLD_PADDEL_VX;
    } else if (cpct_isKeyPressed(Key_P)) {
        vx = BREAKOUT_WORLD_PADDEL_VX;
    }

    ((TEEM_entity *) me)->ph.vx = vx;
}