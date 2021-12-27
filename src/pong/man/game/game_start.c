#include <pong/man/game/game.h>
#include <pong/man/entity/entity.h>
#include <pong/sys/render/render.h>
#include <pong/sys/input/input.h>
#include <pong/sys/ai/ai.h>
#include <pong/sys/physics/physics.h>

void pong_man_game_start(void) {
    _pong_man_game_playing = 1;
}