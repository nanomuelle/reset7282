#include "ers.h"

void ers_update_one(TEEM_entity *e) {
    // si ha cambiado de pos, repintamos la entidad
    if (e->state & EEM_STATE_MOVED) {
        u8 x = e->tr.screen.x;
        u8 shift = x & 0b00000011;
        u8* pmem = ers_get_screen_ptr(
            x,
            e->tr.screen.y
        );

        // actualiza la pos de memoria para pintar
        e->render.pmem = pmem;
        e->render.shift = shift;

        // capture bg
        ers_capture_one_bg(e);

        // draw sprite
        ers_pp_draw_sprite(
            e->render.pmem,
            e->render.sprite,
            shift,
            e->render.w,
            e->render.h
        );

        eem_reset_state_moved(e);
    }
}