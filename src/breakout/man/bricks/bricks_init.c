#include "bricks.h"

void man_bricks_init(void) {
    m_man_bricks_num = 0;
    m_man_bricks_next_bg_free = m_man_bricks_bg_buffer;
    cpct_memset(m_man_bricks_bg_buffer, 0, sizeof(m_man_bricks_bg_buffer));
}
