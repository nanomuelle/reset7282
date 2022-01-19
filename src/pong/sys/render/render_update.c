#include <pong/sys/render/render.h>
#include <pong/man/entity/entity.h>
#include <pong/man/score/score.h>
#include <sys/render/render.h>

#include <pong/pong.h>

void _pong_sys_render_updateOne(TPongEntity *entity) {
    u8* pmem = cpct_getScreenPtr(
        CPCT_VMEM_START, 
        PONG_WORLD_TO_SCREEN_X(entity->x), 
        PONG_WORLD_TO_SCREEN_Y(entity->y)
    );

    // delete
    if (pmem != entity->pmem) {
        cpct_drawSolidBox(
            entity->pmem, 
            PONG_SYS_RENDER_BG_COLOR, 
            entity->render_w, 
            entity->render_h
        );

        // almacena la ultima pos de memoria en la que se ha pintado
        entity->pmem = pmem;

    }

    // paint
    cpct_drawSolidBox(
        pmem, 
        entity->color, 
        entity->render_w, 
        entity->render_h
    );

}

void _pong_sys_render_updateNet() {
    u8 color = cpct_px2byteM1(0, PONG_PEN, PONG_PEN, 0);
    u8 *pmem = cpct_getScreenPtr(
        CPCT_VMEM_START,
        PONG_WORLD_TO_SCREEN_X(0),
        PONG_WORLD_TO_SCREEN_Y(PONG_WORLD_MIN_Y)
    );
    cpct_drawSolidBox(pmem, color, 1, PONG_SYS_RENDER_PHY_TO_PX(PONG_WORLD_H) - 2);
}

void _pong_sys_render_updateScore() {
    _render_printChar(
        48 + pong_man_score_getLeftPlayer(),
        PONG_WORLD_TO_SCREEN_X(-(256 * 3)),
        PONG_WORLD_TO_SCREEN_Y(PONG_WORLD_MIN_Y + (256 * 2)),
        PONG_PEN
    );

    _render_printChar(
        48 + pong_man_score_getRightPlayer(),
        PONG_WORLD_TO_SCREEN_X(256 * (3 - 1)),
        PONG_WORLD_TO_SCREEN_Y(PONG_WORLD_MIN_Y + (256 * 2)),
        PONG_PEN
    );
}

void pong_sys_render_update(void) {
    _pong_sys_render_updateNet();
    _pong_sys_render_updateScore();
    pong_man_entity_forEach(_pong_sys_render_updateOne);
}