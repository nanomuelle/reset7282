#include <pong/man/entity/entity.h>
#include <pong/sys/physics/physics.h>
#include <pong/sys/render/render.h>

void _createEntity(i16 x, i16 y, u16 w, u16 h, i16 vx, i16 vy) {
    TPongEntity *entity = pong_man_entity_create();
    entity->x = x;
    entity->y = y;
    entity->w = w;  // 2 bytes => 4px mode 1
    entity->h = h;
    entity->vx = vx;
    entity->vy = vy;
    entity->color = cpct_px2byteM1(1, 1, 1, 1);
    entity->render_w = HI(entity->w);
    entity->render_h = HI(entity->h);
    entity->pmem = cpct_getScreenPtr(
        CPCT_VMEM_START,
        WORLD_TO_SCREEN_X(x),
        WORLD_TO_SCREEN_Y(y)
    );
}

void pong_man_entity_init(void) {
    TPongEntity *entity;

    _pong_man_entity_numEntities = 0;
    cpct_memset(_pong_man_entity_buffer, 0, PONG_MAN_ENTITY_BUFFER_SIZE * sizeof(TPongEntity));

    // ball
    _createEntity(0, 0, PONG_SYS_PHYSICS_PX_TO_PHY(1), PONG_SYS_PHYSICS_PX_TO_PHY(4), 200, 160);

    // ai paddel
    _createEntity(PONG_SYS_PHYSICS_MIN_X + PONG_SYS_PHYSICS_PX_TO_PHY(2) , 0, PONG_SYS_PHYSICS_PX_TO_PHY(1), PONG_SYS_PHYSICS_PX_TO_PHY(16), 0, 500);
}