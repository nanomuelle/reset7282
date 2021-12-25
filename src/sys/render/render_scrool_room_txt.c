#include <sys/render/render.h>
#include <sys/memory/memory.h>

#include <sys/debug/debug.h>
//
//
//   1 2 3 4 5 6 7 8
//       h o l a       STEP 0: src = 5, dst = 6, w = 4
//         h o l       STEP 1: src = 5, dst = 6, w = 3
//           h o       STEP 2: src = 5, dst = 6, w = 2
//             h       STEP 2: src = 5, dst = 6, w = 1
//                     STEP 2: src = 5, dst = 6, w = 2

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

void _render_scroolRoomTxt(TParamGoEnum dir) {
    switch(dir) {
        case ACTION_PARAM_GO_N:            
        break;
        
        case ACTION_PARAM_GO_S:
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
