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

    c = room->outs.direction[OUT_N] != NO_EXIT ? OUTS_PEN1 : OUTS_PEN2;
    _render_printChar('N', x, y, c);

    x += offset;
    c = room->outs.direction[OUT_S] != NO_EXIT ? OUTS_PEN1 : OUTS_PEN2;
    _render_printChar('S', x, y, c);

    x += offset;
    c = room->outs.direction[OUT_E] != NO_EXIT ? OUTS_PEN1 : OUTS_PEN2;
    _render_printChar('E', x, y, c);

    x += offset;
    c = room->outs.direction[OUT_O] != NO_EXIT ? OUTS_PEN1 : OUTS_PEN2;
    _render_printChar('O', x, y, c);
}

void _update_roomTxt(TRoom *room) {
    _render_typeInBox(room->txt, ROOM_TXT_X, ROOM_TXT_Y, ROOM_TXT_COLS, ROOM_TXT_PEN);
}

void _update_headerLine() {
    u8 *pmem = cpct_getScreenPtr(CPCT_VMEM_START, 0, 10);
    u8 c = cpct_px2byteM1(3, 0, 0, 0);
    cpct_memset(pmem, c, 80);
}

void _update_roomTxtBox() {
    u8 *pmem = cpct_getScreenPtr(CPCT_VMEM_START, ROOM_TXT_BOX_X, ROOM_TXT_BOX_Y);
    u8 ch = cpct_px2byteM1(3, 3, 3, 3);
    u8 cvl = cpct_px2byteM1(0, 0, 3, 3);
    u8 cvr = cpct_px2byteM1(3, 3, 0, 0);

    cpct_drawSolidBox(pmem                     , ch, ROOM_TXT_BOX_W / 2, 2);
    cpct_drawSolidBox(pmem + ROOM_TXT_BOX_W / 2, ch, ROOM_TXT_BOX_W / 2, 2);

    cpct_drawSolidBox(pmem, cvl, 1, ROOM_TXT_BOX_H);

    pmem = cpct_getScreenPtr(CPCT_VMEM_START, ROOM_TXT_BOX_X + ROOM_TXT_BOX_W - 1, ROOM_TXT_BOX_Y);
    cpct_drawSolidBox(pmem, cvr, 1, ROOM_TXT_BOX_H);

    pmem = cpct_getScreenPtr(CPCT_VMEM_START, ROOM_TXT_BOX_X - 3, ROOM_TXT_BOX_Y + ROOM_TXT_BOX_H);
    cpct_drawSolidBox(pmem                     , ch, (ROOM_TXT_BOX_W + 6) / 2, 2);
    cpct_drawSolidBox(pmem + (ROOM_TXT_BOX_W + 6) / 2, ch, (ROOM_TXT_BOX_W + 6) / 2, 2);
}

void _update_roomObjs(TRoom *room) {
    // TODO solo mostrar objs si la habitacion ha sido explorada
    _render_clearBox(
        ROOM_TXT_BOX_X,
        ROOM_TXT_BOX_Y + ROOM_TXT_BOX_H + 2,
        ROOM_TXT_BOX_W / 2,
        10
    );
    _render_clearBox(
        ROOM_TXT_BOX_X + ROOM_TXT_BOX_W / 2,
        ROOM_TXT_BOX_Y + ROOM_TXT_BOX_H + 2,
        ROOM_TXT_BOX_W / 2,
        10
    );

    if (room->explored == EXPLORED) {
        _render_printObjsInRoom(
            room,
            ROOM_TXT_BOX_X + ROOM_TXT_BOX_W - 1,
            ROOM_TXT_BOX_Y + ROOM_TXT_BOX_H + 3
        );
    }
}

void _render_updateRoom(TRoom *room) {
    // header
    _update_roomName(room);
    // _update_roomOutsLabel();
    _update_roomOuts(room);
    _update_headerLine();

    // txt
    _update_roomTxt(room);
    _update_roomTxtBox();

    // objs
    _update_roomObjs(room);
}
