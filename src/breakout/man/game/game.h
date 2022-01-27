#pragma once

#include <globals.h>
#include <breakout/breakout.h>
#include <breakout/sys/collisions/collisions.h>

// PUBLIC
extern void breakout_man_game_init(void);
extern void breakout_man_game_start(void);

extern void breakout_man_game_readInput(void);
extern void breakout_man_game_update(void);
extern void breakout_man_game_render(void);

extern void breakout_man_game_behavior_userInput(void *me);
