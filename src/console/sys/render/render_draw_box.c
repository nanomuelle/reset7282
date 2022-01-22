#include "render.h"

// 0 <= x < 320
// 0 <= y < 200
void csr_draw_box(TEntity* e, u8 pen) {
    u16 x = CSR_WORLD_TO_SCREEN_X(e->world_x);
    u16 y = CSR_WORLD_TO_SCREEN_Y(e->world_y);
    u8 shift = x & 0b00000011;
    u8* pmem = csr_getScreenPtr(x, y);
    u16 color = cpct_px2byteM1(pen, pen, pen, pen);

    #define bgpen 0

    if (shift == 0) {
        cpct_drawSolidBox(pmem, color, e->render_w, e->render_h);
    } else if (shift == 1) {
        color = cpct_px2byteM1(bgpen, pen, pen, pen);
        cpct_drawSolidBox(pmem, color, 1, e->render_h);

        color = cpct_px2byteM1(pen, pen, pen, pen);
        ++pmem;
        cpct_drawSolidBox(pmem, color, e->render_w - 1, e->render_h);

        color = cpct_px2byteM1(pen, bgpen, bgpen, bgpen);
        pmem += e->render_w - 1;
        cpct_drawSolidBox(pmem, color, 1, e->render_h);
    } else if (shift == 2) {
        color = cpct_px2byteM1(bgpen, bgpen, pen, pen);
        cpct_drawSolidBox(pmem, color, 1, e->render_h);

        color = cpct_px2byteM1(pen, pen, pen, pen);
        ++pmem;
        cpct_drawSolidBox(pmem, color, e->render_w - 1, e->render_h);

        color = cpct_px2byteM1(pen, pen, bgpen, bgpen);
        pmem += e->render_w - 1;
        cpct_drawSolidBox(pmem, color, 1, e->render_h);
    } else if (shift == 3) {
        color = cpct_px2byteM1(bgpen, bgpen, bgpen, pen);
        cpct_drawSolidBox(pmem, color, 1, e->render_h);

        color = cpct_px2byteM1(pen, pen, pen, pen);
        ++pmem;
        cpct_drawSolidBox(pmem, color, e->render_w - 1, e->render_h);

        color = cpct_px2byteM1(pen, pen, pen, bgpen);
        pmem += e->render_w - 1;
        cpct_drawSolidBox(pmem, color, 1, e->render_h);
    }



}