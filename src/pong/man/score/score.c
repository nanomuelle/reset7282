#include <pong/man/score/score.h>

u8 _pong_man_score[2] = { 0, 0 };

void pong_man_score_init(void) {
    _pong_man_score[PONG_MAN_SCORE_LEFT_PLAYER] = 0;
    _pong_man_score[PONG_MAN_SCORE_RIGHT_PLAYER] = 0;
}

void pong_man_score_incLeftPlayer(void) {
    _pong_man_score[PONG_MAN_SCORE_LEFT_PLAYER]++;
}

void pong_man_score_incRightPlayer(void) {
    _pong_man_score[PONG_MAN_SCORE_RIGHT_PLAYER]++;
}

u8 pong_man_score_getLeftPlayer(void) {
    return _pong_man_score[PONG_MAN_SCORE_LEFT_PLAYER];
}

u8 pong_man_score_getRightPlayer(void) {
    return _pong_man_score[PONG_MAN_SCORE_RIGHT_PLAYER];
}