#include <cpctelera.h>
#include <sys/render/render.h>
#include <sys/ascii/ascii.h>

void _render_clearBox(u8 x, u8 y, u8 w, u8 h) {
    cpct_drawSolidBox(
        cpct_getScreenPtr(CPCT_VMEM_START, x, y),
        cpct_px2byteM1(2, 2, 2, 2),
        w, h
    );
}

void printMsg(const char* msg, u8 x, u8 y, u8 pen) {
   u8* video_memory_ptr;  // Pointer to video memory
   video_memory_ptr = cpct_getScreenPtr(CPCT_VMEM_START, x, y);
   cpct_setDrawCharM1(pen, 0);
   cpct_drawStringM1(msg, video_memory_ptr);
}

void printChar(u16 ascii, u8 x, u8 y, u8 pen) {
   u8* video_memory_ptr;  // Pointer to video memory
   video_memory_ptr = cpct_getScreenPtr(CPCT_VMEM_START, x, y);
   cpct_setDrawCharM1(pen, 0);
   cpct_drawCharM1(video_memory_ptr, ascii);
}

void _wait() {
    cpct_waitHalts(10);
}

void printInBox(const char* msg, u8 x, u8 y, u8 cols, u8 pen) {    
    u8 col = 0;
    u8 row = y;
    u8* pmem = cpct_getScreenPtr(CPCT_VMEM_START, x, row);

    while( (*msg) != 0) {
        if ((*msg) == ASCII_RETURN || col > cols) {
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
        _wait();
    }
}

void _render_roomOutsLabel() {
    printMsg("SALIDAS:", OUTS_LABEL_X, OUTS_LABEL_Y, OUTS_LABEL_PEN);
}

void _render_roomOuts(TRoom *room) {
    u8 c;
    u8 y = OUTS_Y;
    u8 x = OUTS_X;
    u8 offset = OUTS_KERNEL;

    _render_clearBox( OUTS_X, OUTS_Y, 10, LINE_HEIGHT);

    c = room->outs.direction[OUT_N] != NO_EXIT ? 'N' : ' ';
    printChar(c, x, y, 3);

    x += offset;
    c = room->outs.direction[OUT_S] != NO_EXIT ? 'S' : ' ';
    printChar(c, x, y, 3);

    x += offset;
    c = room->outs.direction[OUT_E] != NO_EXIT ? 'E' : ' ';
    printChar(c, x, y, 3);

    x += offset;
    c = room->outs.direction[OUT_O] != NO_EXIT ? 'O' : ' ';
    printChar(c, x, y, 3);
}


void _render_roomName(TRoom *room) {
    _render_clearBox(ROOM_NAME_X, ROOM_NAME_Y, ROOM_NAME_W, LINE_HEIGHT);
    printMsg(room->name, ROOM_NAME_X, ROOM_NAME_Y, ROOM_PEN);
}

void _render_roomTxt(TRoom *room) {
    _render_clearBox( ROOM_TXT_X, ROOM_TXT_Y, 2 + (ROOM_TXT_COLS * 8 / 4), 60);
    printInBox(room->txt, ROOM_TXT_X, ROOM_TXT_Y, ROOM_TXT_COLS, ROOM_TXT_PEN);
}

void sys_render_renderRoom(TRoom *room) {
    _render_roomName(room);
    _render_roomOutsLabel();
    _render_roomOuts(room);
    _render_roomTxt(room);
}

void sys_render_renderPrompt(TPrompt *prompt) {
    printChar(PROMPT_CHAR, PROMPT_X, PROMPT_Y, 2);
    printMsg(prompt->buffer, PROMPT_X + 3, PROMPT_Y, 1);
    printChar(PROMPT_CURSOR_CHAR, PROMPT_X + 3 + prompt->cursor_pos * 2, PROMPT_Y, 2);
}

