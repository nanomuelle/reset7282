#include <sys/render/render.h>
#include <sys/memory/memory.h>

#include <sys/debug/debug.h>

void _scroolRoomTxtE() {
    u8 h = 0;
    u8 w = ROOM_TXT_W - SYS_RENDER_ROOM_SCROLL_IX + SYS_RENDER_ROOM_SCROLL_IX;
    u8 dst_x = ROOM_TXT_X + ROOM_TXT_W - 1;

    while (w != 0) {
        while (h < ROOM_TXT_H) {
            u8 *dst = cpct_getScreenPtr(CPCT_VMEM_START, dst_x, ROOM_TXT_Y + h);
            u8 *src = dst - SYS_RENDER_ROOM_SCROLL_IX;

            sys_mem_memcpyRtl(dst, src, w);
            ++h;
        }
        w -= SYS_RENDER_ROOM_SCROLL_IX;
        h = 0;

        // cpct_waitVSYNC();
    }
}

void _scroolRoomTxtO() {
    u8 h = 0;
    u8 w = ROOM_TXT_W;

    while (w > 0) {
        while (h < ROOM_TXT_H) {
            u8 *src = cpct_getScreenPtr(CPCT_VMEM_START, ROOM_TXT_X + SYS_RENDER_ROOM_SCROLL_IX, ROOM_TXT_Y + h);
            u8 *dst = src - SYS_RENDER_ROOM_SCROLL_IX;

            sys_mem_memcpy(dst, src, w);
            ++h;
        }
        w -= SYS_RENDER_ROOM_SCROLL_IX;
        h = 0;
        // cpct_waitVSYNC();
    }
}

//
//       1 2 3 4 5 6 7 8
//  Y-1
//  Y      X X X X
//  Y+1    Y Y Y Y
//  Y+2    Z Z Z Z
//
//       1 2 3 4 5 6 7 8
//  Y-1
//  Y
//  Y+1    X X X X
//  Y+2    Y Y Y Y
//
//       1 2 3 4 5 6 7 8
//  Y-1
//  Y
//  Y+1
//  Y+2    X X X X
//
void _scroolRoomTxtN() {
    u8 bottom = ROOM_TXT_Y + ROOM_TXT_H;
    u8 h = ROOM_TXT_H + 1;
    while (h > 0) {
        u8 lines = h;
        while (lines > 0) {
            u8 *src = cpct_getScreenPtr(CPCT_VMEM_START, ROOM_TXT_X, bottom - 1);
            u8 *dst = cpct_getScreenPtr(CPCT_VMEM_START, ROOM_TXT_X, bottom);

            sys_mem_memcpy(dst, src, ROOM_TXT_W);
            --bottom;
            --lines;
        }
        bottom = ROOM_TXT_Y + ROOM_TXT_H;
        --h;
    }
}

//
//       1 2 3 4 5 6 7 8
//  Y-1
//  Y      X X X X
//  Y+1    Y Y Y Y
//  Y+2    Z Z Z Z
//  Y+3
//
//       1 2 3 4 5 6 7 8
//  Y-1
//  Y      Y Y Y Y
//  Y+1    Z Z Z Z
//  Y+2
//  Y+3
//
//       1 2 3 4 5 6 7 8
//  Y-1
//  Y      Z Z Z Z
//  Y+1
//  Y+2
//  Y+3
//
void _scroolRoomTxtS() {
    u8 top = ROOM_TXT_Y;
    u8 h = ROOM_TXT_H + 1;
    while (h > 0) {
        u8 lines = h;
        while (lines > 0) {
            u8 *dst = cpct_getScreenPtr(CPCT_VMEM_START, ROOM_TXT_X, top);
            u8 *src = cpct_getScreenPtr(CPCT_VMEM_START, ROOM_TXT_X, top + 1);

            sys_mem_memcpy(dst, src, ROOM_TXT_W);
            ++top;
            --lines;
        }
        top = ROOM_TXT_Y;
        --h;
    }
}

void _render_scroolRoomTxt(TParamGoEnum dir) {
    switch(dir) {
        case ACTION_PARAM_GO_N:
            _scroolRoomTxtN();
        break;

        case ACTION_PARAM_GO_S:
            _scroolRoomTxtS();
        break;

        case ACTION_PARAM_GO_E:
            _scroolRoomTxtE();
        break;

        case ACTION_PARAM_GO_O:
            _scroolRoomTxtO();
        break;
        
        default:
        
    }
}
