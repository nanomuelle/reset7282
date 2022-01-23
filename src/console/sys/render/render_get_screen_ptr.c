#include "render.h"

//
// 0 < x < 256
// 0 < y < 96
//
u8* csr_getScreenPtr(u8 x, u8 y) {
    return cpct_getScreenPtr(
        CPCT_VMEM_START,
        (u8) CSR_OFFSET_X_BYTES + M1_PX_TO_BYTES(x), // px to bytes
        (u8) CSR_OFFSET_Y + y
    );
}