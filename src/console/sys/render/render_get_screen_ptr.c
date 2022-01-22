#include "render.h"

u8* csr_getScreenPtr(u16 x, u16 y) {
    return cpct_getScreenPtr(
        CPCT_VMEM_START,
        (u8) (x / 4), // px to bytes
        (u8) y
    );
}