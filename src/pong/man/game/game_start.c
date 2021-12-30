#include <pong/man/game/game.h>
#include <pong/man/score/score.h>

void pong_man_game_start(void) {
    _pong_man_game_playing = 1;
    pong_man_score_init();
}