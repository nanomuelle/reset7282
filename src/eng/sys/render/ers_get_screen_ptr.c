#include "ers.h"

//
// 0 < x < 256
// 0 < y < 128
//
u8* ers_get_screen_ptr(u8 x, u8 y) {
    return cpct_getScreenPtr(
        CPCT_VMEM_START,
        ERS_OFFSET_X_BYTES + ERS_PX_TO_BYTES(x),
        ERS_OFFSET_Y_BYTES + y
    );
}