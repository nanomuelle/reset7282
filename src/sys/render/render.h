#ifndef RESET_SYS_RENDER
#define RESET_SYS_RENDER

#include <man/rooms/rooms.h>
#include <man/prompt/prompt.h>
#include <man/history/history.h>

#define PROMPT_X 0
#define PROMPT_Y 190
#define PROMPT_CHAR '?'
#define PROMPT_CURSOR_CHAR 0x8F

////////// PRIVATE
extern void printMsg(const char* msg, u8 x, u8 y, u8 pen);
extern void printChar(u16 ascii, u8 x, u8 y);

////////// PUBLIC
extern void sys_render_init(void);
extern void sys_render_renderRoom(TRoom *);
extern void sys_render_renderPrompt(TPrompt *);
extern void sys_render_renderHistory(THistory *);
extern void sys_render_clearScreen();

#endif