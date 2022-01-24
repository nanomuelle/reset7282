#include "eem.h"

TEEM_entity *eem_get_by_id(u8 id) {
    TEEM_entity *e = m_eem_buffer;
    while (e->id != id) {
        ++e;
    };

    return e;
}