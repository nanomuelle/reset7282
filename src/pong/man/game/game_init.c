#include <pong/man/game/game.h>
#include <pong/man/entity/entity.h>
#include <pong/man/score/score.h>

#include <pong/sys/render/render.h>
#include <pong/sys/input/input.h>
#include <pong/sys/ai/ai.h>
#include <pong/sys/physics/physics.h>

void pong_man_game_init(void) {
    pong_man_entity_init();
    pong_man_score_init();

    pong_sys_render_init();
    pong_sys_input_init();
    pong_sys_ai_init();
    pong_sys_physics_init();
}