#ifndef RESET_SYS_RENDER
#define RESET_SYS_RENDER

#include <man/rooms/rooms.h>
#include <man/prompt/prompt.h>
#include <man/history/history.h>

#define LINE_HEIGHT 10

#define ROOM_NAME_X     0
#define ROOM_NAME_Y     0
#define ROOM_NAME_W     51 // bytes
#define ROOM_PEN        3

#define OUTS_LABEL_X    52
#define OUTS_LABEL_Y    ROOM_NAME_Y
#define OUTS_LABEL_PEN  1

#define OUTS_X          69
#define OUTS_Y          ROOM_NAME_Y
#define OUTS_KERNEL     3   // separacion entre caracteres en bytes

#define ROOM_TXT_Y      30
#define ROOM_TXT_X      8
#define ROOM_TXT_COLS   30
#define ROOM_TXT_PEN    1

#define PROMPT_X        0
#define PROMPT_Y        180
#define PROMPT_CHAR     ':'
#define PROMPT_CURSOR_CHAR 0x8F

////////// PRIVATE
extern void printMsg(const char* msg, u8 x, u8 y, u8 pen);
extern void printChar(u16 ascii, u8 x, u8 y, u8 pen);

////////// PUBLIC
extern void sys_render_init(void);
extern void sys_render_renderRoom(TRoom *);
extern void sys_render_renderPrompt(TPrompt *);
extern void sys_render_renderHistory(THistory *);
extern void sys_render_clearScreen();

#endif