#ifndef RESET_SYS_RENDER
#define RESET_SYS_RENDER

#include <globals.h>
#include <man/rooms/rooms.h>
#include <man/prompt/prompt.h>
#include <man/history/history.h>
#include <sys/parser/parser.h>

#define SYS_RENDER_ROOM_SCROLL_IX   1   // BYTES

////////// PRIVATE
extern void _render_printMsg(const char* msg, u8 x, u8 y, u8 pen);
extern void _render_printChar(u16 ascii, u8 x, u8 y, u8 pen);
extern void _render_typeInBox(const char* msg, u8 x, u8 y, u8 cols, u8 pen);

extern void _render_printObjsInRoom(const TRoom *room);
extern void _render_printObjsInInventory(void);

extern void _render_clearBox(u8 x, u8 y, u8 w, u8 h);

extern void _render_clearRoomTxt();
extern void _render_scroolRoomTxt(TParamGoEnum dir);

extern void _render_updateRoom(TRoom *);
extern void _render_updateHistory(THistory *);

extern const u8 sprite_bg[ROOM_TXT_BOX_W * ROOM_TXT_BOX_H];
// __code __at (0x7ff0)

////////// PUBLIC
extern void sys_render_init(void);
extern void sys_render_clearScreen(void) __z88dk_callee;
extern void sys_render_update(TAction *action, TRoom *room, THistory *history, TPrompt *prompt);
extern void sys_render_updatePrompt(TPrompt *prompt);

extern void sys_render_clearRoom(TAction *action);
#endif