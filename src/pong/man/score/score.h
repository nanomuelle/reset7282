#ifndef PONG_MAN_SCORE
#define PONG_MAN_SCORE

#include <cpctelera.h>
#include <sys/debug/debug.h>

#define PONG_MAN_SCORE_LEFT_PLAYER  0
#define PONG_MAN_SCORE_RIGHT_PLAYER 1

// PUBLIC
extern void pong_man_score_init(void);
extern void pong_man_score_incLeftPlayer(void);
extern void pong_man_score_incRightPlayer(void);
extern u8 pong_man_score_getLeftPlayer(void);
extern u8 pong_man_score_getRightPlayer(void);

#endif