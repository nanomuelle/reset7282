#include <sys/render/render.h>
#include <sys/ascii/ascii.h>
#include <assets/lightbulb.h>

void _update_roomName(TRoom *room) {
    _render_clearBox(ROOM_NAME_X, ROOM_NAME_Y, ROOM_NAME_W, LINE_HEIGHT);
    _render_printMsg(room->name, ROOM_NAME_X, ROOM_NAME_Y, ROOM_PEN);
}

void _update_roomOuts(TRoom *room) {
    const u16 const outChar[] = {'N', 'S', 'E', 'O'};
    u8 x = OUTS_X;
    u8 pen = man_rooms_isDark(room) ? OUTS_PEN_DARK : OUTS_PEN;

    _render_clearBox( OUTS_X, OUTS_Y, 11, LINE_HEIGHT);

    for (TRoomOutsEnum out = OUT_N; out <= OUT_O; out++) {
        if (room->outs.direction[out] != NO_EXIT) {
            _render_printChar(outChar[out], x, OUTS_Y, pen);
        }
        x += OUTS_KERNEL;
    }
}

void _update_roomTxt(TRoom *room) {
    _render_clearBox( ROOM_TXT_BOX_X, ROOM_TXT_BOX_Y, ROOM_TXT_BOX_W, ROOM_TXT_BOX_H);
    _render_typeInBox(
        man_rooms_isDark(room) ? room->txtDark : room->txt,
        ROOM_TXT_X,
        ROOM_TXT_Y,
        ROOM_TXT_COLS,
        ROOM_TXT_PEN
    );
}

void _update_headerLine(TRoom *room) {
    u8 *pmem = cpct_getScreenPtr(CPCT_VMEM_START, 0, LINE_HEIGHT);
    u8 c = man_rooms_isDark(room) 
        ? cpct_px2byteM1(3, 0, 0, 0)
        : cpct_px2byteM1(2, 0, 0, 0)
    ;
    cpct_memset(pmem, c, 80);
}

void _update_roomTxtBox(TRoom *room) {
    u8 *pmem = cpct_getScreenPtr(CPCT_VMEM_START, ROOM_TXT_BOX_X, ROOM_TXT_BOX_Y);
    u8 ch = cpct_px2byteM1(3, 3, 3, 3);
    u8 cvl = cpct_px2byteM1(0, 0, 3, 3);
    u8 cvr = cpct_px2byteM1(3, 3, 0, 0);

    // horizontal lines
    cpct_drawSolidBox(pmem                     , ch, ROOM_TXT_BOX_W / 2, 1);
    cpct_drawSolidBox(pmem + ROOM_TXT_BOX_W / 2, ch, ROOM_TXT_BOX_W / 2, 1);

    // vertical lines
    cpct_drawSolidBox(pmem, cvl, 1, ROOM_TXT_BOX_H);

    pmem = cpct_getScreenPtr(CPCT_VMEM_START, ROOM_TXT_BOX_X + ROOM_TXT_BOX_W - 1, ROOM_TXT_BOX_Y);
    cpct_drawSolidBox(pmem, cvr, 1, ROOM_TXT_BOX_H);

    pmem = cpct_getScreenPtr(CPCT_VMEM_START, ROOM_TXT_BOX_X - 3, ROOM_TXT_BOX_Y + ROOM_TXT_BOX_H);
    cpct_drawSolidBox(pmem                     , ch, (ROOM_TXT_BOX_W + 6) / 2, 2);
    cpct_drawSolidBox(pmem + (ROOM_TXT_BOX_W + 6) / 2, ch, (ROOM_TXT_BOX_W + 6) / 2, 2);
}

void _update_roomObjs(TRoom *room) {
    // TODO: buscar objetos que están everywhere y pintarlos de arriba abajo
    // lightbulb
    u8* lightbulb = man_rooms_isDark(room) ? g_tile_lightbulb_0 : g_tile_lightbulb_1;

    cpct_drawSprite(
        lightbulb,
        cpct_getScreenPtr(CPCT_VMEM_START, 0, ROOM_TXT_BOX_Y),
        G_TILE_LIGHTBULB_0_W, G_TILE_LIGHTBULB_0_H
    );

    _render_printObjsInRoom(room);
}

void _render_updateRoom(TRoom *room) {
    // header
    _update_roomName(room);
    _update_roomOuts(room);

    // txt
    _update_roomTxt(room);
    _update_roomTxtBox(room);

    // objs
    _update_roomObjs(room);
}
