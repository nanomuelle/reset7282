#include <pong/sys/render/render.h>
#include <pong/man/entity/entity.h>

void _pong_sys_render_updateOne(TPongEntity *entity) {
    u8* pmem = cpct_getScreenPtr(CPCT_VMEM_START, entity->x, entity->y);
    u8 color = cpct_px2byteM1(1, 1, 1, 1);
    cpct_drawSolidBox(pmem, color, entity->w, entity->h);
}

void pong_sys_render_update(void) {
    pong_man_entity_forEach(_pong_sys_render_updateOne);
}