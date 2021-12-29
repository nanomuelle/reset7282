#ifndef PONG_MAN_GAME
#define PONG_MAN_GAME

#include <cpctelera.h>
#include <pong/man/entity/entity.h>

// PRIVATE
extern u8   _pong_man_game_playing;
extern u8   _pong_man_game_isPlaying(void);

// PUBLIC
extern void pong_man_game_init(void);
extern void pong_man_game_start(void);
extern void pong_man_game_update(void);

extern void pong_man_game_behavior_followBall(void *selfEntity);
extern void pong_man_game_behavior_userInput(void *selfEntity);
#endif