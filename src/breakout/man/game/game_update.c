#include <breakout/man/game/game.h>
#include <breakout/sys/ai/ai.h>
#include <breakout/sys/physics/physics.h>
#include <man/entity/entity.h>

TEntity *ball;

u8 _breakout_man_game_checkCollisionsVsBall(TEntity *other) {
    if (other == ball) {
        return 0;
    }

    if (breakout_sys_physics_checkCollision(ball, other)) {
        i16 vy = ball->world_vy;
        ball->world_vy = -vy;

        if (other->id == BREAKOUT_ENTITY_ID_BRICK) {
            other->state = ENTITY_STATE_DEAD;
        } else if (other->id == BREAKOUT_ENTITY_ID_PADDEL) {
            // i16 vx = ball->world_vx;
            // ball->world_vx += (vx >> 1);
        }

        return 1;
    }

    return 0;
}

void _breakout_man_game_checkCollisions(void) {
    ball = man_entity_getById(BREAKOUT_ENTITY_ID_BALL);
    man_entity_forEachUntil(_breakout_man_game_checkCollisionsVsBall);

    // TEntity *entity = m_man_entity_buffer;
    // for (u8 i = 0; i < m_man_entity_numEntities; ++i, ++entity) {
    //     if (entity == ball) {
    //         continue;
    //     }

    //     if (breakout_sys_physics_checkCollision(ball, entity)) {
    //         ball->vy = -ball->vy;

    //         if (entity->id == BREAKOUT_ENTITY_ID_BRICK) {
    //             entity->state = 0;
    //         } else if (entity->id == BREAKOUT_ENTITY_ID_PADDEL) {
    //             ball->vx += (entity->vx >> 1);
    //         }

    //         return;
    //     }
    // }
}

void breakout_man_game_update(void) {
    // man_entity_update();

    breakout_sys_ai_update();
    breakout_sys_physics_update();
    _breakout_man_game_checkCollisions();
}