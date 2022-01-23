#include <sys/render/render.h>

void _render_clearRoomTxt(void) {
    u8 color = cpct_px2byteM1(0, 0, 0, 0);
    _render_clearBox( ROOM_TXT_BOX_X, ROOM_TXT_BOX_Y, ROOM_TXT_BOX_W, ROOM_TXT_BOX_H, color);
}

void sys_render_clearRoom(TAction *action) {
    if (action->type == ACTION_TYPE_GO) {
        _render_scroolRoomTxt(action->param1.go_param);
    } else {
        _render_clearRoomTxt();
    }
}
