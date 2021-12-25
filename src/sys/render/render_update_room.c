#include <sys/render/render.h>
#include <sys/ascii/ascii.h>



void _update_roomName(TRoom *room) {
    _render_clearBox(ROOM_NAME_X, ROOM_NAME_Y, ROOM_NAME_W, LINE_HEIGHT);
    _render_printMsg(room->name, ROOM_NAME_X, ROOM_NAME_Y, ROOM_PEN);
}

void _update_roomOutsLabel() {
    _render_printMsg("SALIDAS:", OUTS_LABEL_X, OUTS_LABEL_Y, OUTS_LABEL_PEN);
}

void _update_roomOuts(TRoom *room) {
    u8 c;
    u8 y = OUTS_Y;
    u8 x = OUTS_X;
    u8 offset = OUTS_KERNEL;

    _render_clearBox( OUTS_X, OUTS_Y, 10, LINE_HEIGHT);

    c = room->outs.direction[OUT_N] != NO_EXIT ? 'N' : ' ';
    _render_printChar(c, x, y, 3);

    x += offset;
    c = room->outs.direction[OUT_S] != NO_EXIT ? 'S' : ' ';
    _render_printChar(c, x, y, 3);

    x += offset;
    c = room->outs.direction[OUT_E] != NO_EXIT ? 'E' : ' ';
    _render_printChar(c, x, y, 3);

    x += offset;
    c = room->outs.direction[OUT_O] != NO_EXIT ? 'O' : ' ';
    _render_printChar(c, x, y, 3);
}

void _update_roomTxt(TRoom *room) {
    _render_typeInBox(room->txt, ROOM_TXT_X, ROOM_TXT_Y, ROOM_TXT_COLS, ROOM_TXT_PEN);
}

void _update_headerLine() {
    u8 *pmem = cpct_getScreenPtr(CPCT_VMEM_START, 0, 10);
    u8 c = cpct_px2byteM1(2, 2, 0, 0);
    cpct_memset(pmem, c, 80);
}

void _render_updateRoom(TRoom *room) {
    _update_roomName(room);
    _update_roomOutsLabel();
    _update_roomOuts(room);
    _update_headerLine();
    _update_roomTxt(room);
}
