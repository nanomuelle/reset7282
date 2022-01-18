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
        ball->world_x -= ball->world_vx;
        ball->world_y -= ball->world_vy;
        ball->world_vy = -ball->world_vy;
        // comprobar por que lado del ladrillo hemos chocado para el rebote
        // {
        //     // chocado por la izquierda?
        //     i16 x = ball->world_x;
        //     i16 w = ball->world_w;
        //     i16 right = x + w;

        //     i16 other_x = other->world_x;
        //     i16 other_right = other_x + other->world_w;

        //     if ( ball->world_vx > 0 && (right >= other_x && right <= other_x + w)) {
        //         ball->world_vx = -ball->world_vx;
        //     } else if ( ball->world_vx < 0 && x < other_right && x > other_right - w) {
        //         ball->world_vx = -ball->world_vx;
        //     }
        // }

        // {
        //     i16 y = ball->world_y;
        //     i16 h = ball->world_h;
        //     i16 bottom = y + h;
        //     i16 other_y = other->world_y;
        //     i16 other_bottom = other_y + other->world_h;

        //     if (
        //         (bottom >= other_y && bottom <= other_y + h) ||
        //         (y < other_bottom && y > other_bottom - h)
        //     ) {
        //         ball->world_vy = -ball->world_vy;
        //     }
        // }

        if (other->id == BREAKOUT_ENTITY_ID_BRICK) {
            // marcar ladrillo para eliminar
            other->state = ENTITY_STATE_DEAD;

        } else if (other->id == BREAKOUT_ENTITY_ID_PADDEL) {
            // i16 vx = ball->world_vx;
            // ball->world_vx += (vx >> 1);
        }
        other->world_x = other->world_x - other->world_vx;
        other->world_y = other->world_y - other->world_vy;
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