#ifndef PONG_MAN_GAME
#define PONG_MAN_GAME

#include <cpctelera.h>

// PRIVATE
extern u8   _pong_man_game_playing;

// PUBLIC
extern void pong_man_game_init(void);
extern void pong_man_game_play(void);
extern u8   pong_man_game_isPlaying(void);

#endif