#include <pong/man/entity/entity.h>

void pong_man_entity_init(void) {
    TPongEntity *entity;

    _pong_man_entity_numEntities = 0;
    cpct_memset(_pong_man_entity_buffer, 0, PONG_MAN_ENTITY_BUFFER_SIZE * sizeof(TPongEntity));

    // ball
    entity = pong_man_entity_create();
    entity->x = 40;
    entity->y = 100;
    entity->w = 2;  // 2 bytes => 4px mode 1
    entity->h = 8;
    entity->vx = 1;
    entity->vy = 1;

    // ai paddel
    entity = pong_man_entity_create();
    entity->x = 2;
    entity->y = 78;
    entity->w = 2;  // 2 bytes => 4px mode 1
    entity->h = 24;
    entity->vx = 0;
    entity->vy = 0;

}