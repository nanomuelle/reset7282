#include <cpctelera.h>
#include <sys/render/render.h>

void printMsg(const char* msg, u8 x, u8 y, u8 pen) {
   u8* video_memory_ptr;  // Pointer to video memory
   video_memory_ptr = cpct_getScreenPtr(CPCT_VMEM_START, x, y);
   cpct_setDrawCharM1(pen, 0);
   cpct_drawStringM1(msg, video_memory_ptr);
}

void printChar(u16 ascii, u8 x, u8 y) {
   u8* video_memory_ptr;  // Pointer to video memory
   video_memory_ptr = cpct_getScreenPtr(CPCT_VMEM_START, x, y);
   cpct_setDrawCharM1(3, 0);
   cpct_drawCharM1(video_memory_ptr, ascii);
}

void renderExits(TRoom *room) {
    u8 c;
    u8 y = 8;
    u8 x = 51;
    u8 offset = 3;

    printMsg("SALIDAS: ", x, y, 1);
    x = 69;
    c = room->outs.direction[OUT_N] != NO_EXIT ? 'N' : ' ';
    printChar(c, x, y);

    x += offset;
    c = room->outs.direction[OUT_S] != NO_EXIT ? 'S' : ' ';
    printChar(c, x, y);

    x += offset;
    c = room->outs.direction[OUT_E] != NO_EXIT ? 'E' : ' ';
    printChar(c, x, y);

    x += offset;
    c = room->outs.direction[OUT_O] != NO_EXIT ? 'O' : ' ';
    printChar(c, x, y);
}

void sys_render_renderRoom(TRoom *room) {
    printMsg(room->name, 0, 8, 3);
    renderExits(room);
    printMsg(room->txt, 0, 32, 1);
}

void sys_render_renderPrompt(TPrompt *prompt) {
    printChar(PROMPT_CHAR, PROMPT_X, PROMPT_Y);
    printMsg(prompt->buffer, PROMPT_X + 3, PROMPT_Y, 1);
    printChar(PROMPT_CURSOR_CHAR, PROMPT_X + 3 + prompt->cursor_pos * 2, PROMPT_Y);
}

