#include <pong/man/game/game.h>
#include <pong/man/entity/entity.h>
#include <pong/sys/render/render.h>
#include <pong/sys/input/input.h>
#include <pong/sys/ai/ai.h>
#include <pong/sys/physics/physics.h>

void pong_man_game_play(void) {
    pong_man_game_init();

    _pong_man_game_playing = 1;
    while(pong_man_game_isPlaying()) {
        pong_sys_input_update();
        pong_sys_ai_init();
        pong_sys_physics_update();
        pong_sys_render_update();
    }
}