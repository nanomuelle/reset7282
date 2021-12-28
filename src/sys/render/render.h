#ifndef RESET_SYS_RENDER
#define RESET_SYS_RENDER

#include <globals.h>
#include <man/rooms/rooms.h>
#include <man/prompt/prompt.h>
#include <man/history/history.h>
#include <sys/parser/parser.h>

#define LINE_HEIGHT    10

#define ROOM_NAME_X     0
#define ROOM_NAME_Y     0
#define ROOM_NAME_W     51 // bytes
#define ROOM_PEN        3

#define OUTS_LABEL_X    52
#define OUTS_LABEL_Y    ROOM_NAME_Y
#define OUTS_LABEL_PEN  2

#define OUTS_X          69
#define OUTS_Y          ROOM_NAME_Y
#define OUTS_KERNEL     3   // separación entre caracteres en bytes
#define OUTS_PEN        1

#define PROMPT_X        0
#define PROMPT_Y        178
#define PROMPT_CHAR     ':'
#define PROMPT_CURSOR_CHAR 0x8F

#define SYS_RENDER_ROOM_SCROLL_IX   1   // BYTES

////////// PRIVATE
extern void _render_printMsg(const char* msg, u8 x, u8 y, u8 pen);
extern void _render_printChar(u16 ascii, u8 x, u8 y, u8 pen);
extern void _render_typeInBox(const char* msg, u8 x, u8 y, u8 cols, u8 pen);

extern void _render_printObjsInRoom(const TRoom *room, const u8 x, const u8 y);

extern void _render_clearBox(u8 x, u8 y, u8 w, u8 h);

extern void _render_clearRoomTxt();
extern void _render_scroolRoomTxt(TParamGoEnum dir);

extern void _render_updateRoom(TRoom *);
extern void _render_updateHistory(THistory *);


////////// PUBLIC
extern void sys_render_init(void);
extern void sys_render_clearScreen(void) __z88dk_callee;
extern void sys_render_update(TAction *action, TRoom *room, THistory *history, TPrompt *prompt);
extern void sys_render_updatePrompt(TPrompt *prompt);

extern void sys_render_clearRoom(TAction *action);
#endif