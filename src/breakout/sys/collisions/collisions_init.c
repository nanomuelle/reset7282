#include <breakout/sys/collisions/collisions.h>

TEEM_entity* m_breakout_sys_collisions_ball;
TEEM_entity* m_breakout_sys_collisions_paddel;

extern void breakout_sys_collisions_init(void) {
    m_breakout_sys_collisions_ball = eem_get_by_id(BRK_ENTITY_ID_BALL);
    m_breakout_sys_collisions_paddel = eem_get_by_id(BRK_ENTITY_ID_PADDEL);
}