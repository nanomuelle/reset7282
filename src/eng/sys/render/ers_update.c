#include "ers.h"
#include <sys/render/render.h>

void m_ers_restore_one(TEEM_entity *e) {
    u8 w = e->render.w;
    if (e->render.shift == 0) {
        --w;
    }
    cpct_drawSprite(
        e->render.sprite_bg,
        e->render.pmem,
        w,
        e->render.h
    );
}

void m_ers_restore_one_dead(TEEM_dead_entity* me) {
    m_ers_restore_one(me->e);
}

void m_ers_restore_one_redraw(TEEM_redraw_entity* me) {
    TEEM_entity *e = me->e;

    if ((e->state & EEM_STATE_DEAD) == 0) {
        m_ers_restore_one(e);
    }
}

void m_ers_restore_one_moved(TEEM_moved_entity* me) {
    TEEM_entity *e = me->e;

    if (e->state & EEM_STATE_DEAD) {
        return;
    }

    {
        u8 x = e->tr.screen.x;
        u8 shift = x & 0b00000011;
        u8* pmem = ers_get_screen_ptr(
            x,
            e->tr.screen.y
        );

        if (e->render.pmem != pmem || e->render.shift != shift) {
            if ((e->state & EEM_STATE_REDRAW) == 0) {
                m_ers_restore_one(e);
            }
            e->render.pmem = pmem;
            e->render.shift = shift;
            eem_set_state_redraw(e);
        }
    }
}

void m_ers_capture_one(TEEM_redraw_entity* me) {
    TEEM_entity *e = me->e;
    if ((e->state & EEM_STATE_DEAD) == 0) {
        ers_capture_one_bg(e);
    }
}

void m_ers_redraw_one(TEEM_redraw_entity *re) {
    TEEM_entity* e = re->e;

    if (e->state & EEM_STATE_DEAD) {
        return;
    }

    // draw sprite
    ers_pp_draw_sprite(
        e->render.pmem,
        e->render.sprite,
        e->render.shift,
        e->render.w,
        e->render.h
    );
    e->state &= EEM_STATE_REDRAW_MASK;
}

void ers_update(void) {
    // restore bg
    eem_forEachDead(m_ers_restore_one_dead);
    eem_forEachRedraw(m_ers_restore_one_redraw);
    eem_forEachMoved(m_ers_restore_one_moved);

    // capture bg
    eem_forEachRedraw(m_ers_capture_one);

    // draw entities
    eem_forEachRedraw(m_ers_redraw_one);
}
