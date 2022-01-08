#ifndef BREAKOUT_MAN_GAME
#define BREAKOUT_MAN_GAME

// PRIVATE
#include <globals.h>

// PUBLIC
extern void breakout_man_game_init(void);
extern void breakout_man_game_start(void);

extern void breakout_man_game_readInput(void);
extern void breakout_man_game_update(void);
extern void breakout_man_game_render(void);

#endif