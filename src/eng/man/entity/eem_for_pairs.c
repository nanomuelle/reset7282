#include "eem.h"
#include <stdio.h>

void eem_for_pairs(TEEM_callback_pair callback, u8 state_mask1, u8 state_mask2) {
    TEEM_entity* e1 = m_eem_buffer;

    while(e1->state != EEM_STATE_INVALID) {
        TEEM_entity* e2 = e1 + 1;
        if ((e1->state & state_mask1) == state_mask1) {
            while(e2->state != EEM_STATE_INVALID) {
                if ((e2->state & state_mask2) == state_mask2) {
                    callback(e1, e2);
                }
                ++e2;
            }
        }
        ++e1;
    }
}

// 7 0b00000111
// 3 0b00000011

