#include <sys/render/render.h>

void _render_clearRoomTxt(void) {
    _render_clearBox( ROOM_TXT_X, ROOM_TXT_Y, ROOM_TXT_W, ROOM_TXT_H);
}

void sys_render_clearRoom(TAction *action) {
    if (action->type == ACTION_TYPE_GO) {
        _render_scroolRoomTxt(action->param1.go_param);
    } else {
        _render_clearRoomTxt();
    }
}
