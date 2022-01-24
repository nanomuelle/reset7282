#include "ers.h"

void ers_update_one(TEEM_entity *e) {
    // si ha cambiado de pos, repintamos la entidad
    if (e->state & EEM_STATE_MOVED) {
        u8* pmem = ers_get_screen_ptr(
            e->tr.screen.x,
            e->tr.screen.y
        );

        // actualiza la pos de memoria para pintar
        e->render.pmem = pmem;

        // capture bg
        ers_capture_one_bg(e);

        // draw sprite
        // u8 x = CSR_PHY_TO_PX(e->world_x);
        // u8 shift = e->tr.screen.x & 0b00000011;
        ers_pp_draw_sprite(
            e->render.pmem,
            e->render.sprite,
            e->tr.screen.x & 0b00000011, // shift
            e->render.w,
            e->render.h
        );

        eem_reset_state_moved(e);
    }
}