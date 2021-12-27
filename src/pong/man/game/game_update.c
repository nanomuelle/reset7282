#include <pong/man/game/game.h>
#include <pong/sys/physics/physics.h>

void pong_man_game_update(void) {
    pong_sys_physics_update();
}