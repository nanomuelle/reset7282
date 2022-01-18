#include <sys/render/render.h>
#include <sys/ascii/ascii.h>

void _render_typeInBox(const char* msg, u8 x, u8 y, u8 cols, u8 pen) {
    u8 col = 0;
    u8 row = y;
    u8* pmem = cpct_getScreenPtr(CPCT_VMEM_START, x, row);

    while( (*msg) != 0) {
        if ((*msg) == ASCII_RETURN || col == cols) {
            col = 0;
            row += 10;
            pmem = cpct_getScreenPtr(CPCT_VMEM_START, x, row);
        };

        if ((*msg) != ASCII_RETURN) {
            cpct_drawCharM1_f(pmem, pen, 0, *msg);
            pmem += 2;
            ++col;
        }

        // next char position
        ++msg;
        // cpct_waitHalts(10);
    }
}