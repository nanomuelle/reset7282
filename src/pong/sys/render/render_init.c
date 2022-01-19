#include <pong/sys/render/render.h>
#include <sys/render/render.h>

#include <assets/pong_odyse.h>
#include <assets/pong_title.h>
#include <pong/pong.h>

// const u8* const g_odyssey[9] = {
const u8* const odyssey[] = {
    g_sprite_pong_odyse_0, // O
    g_sprite_pong_odyse_1, // D
    g_sprite_pong_odyse_2, // Y
    g_sprite_pong_odyse_3, // S
    g_sprite_pong_odyse_3, // S
    g_sprite_pong_odyse_4, // E
    g_sprite_pong_odyse_2, // Y
};

void _pong_sys_render_pong(u8 x, u8 y) {
    u8* pmem = cpct_getScreenPtr(CPCT_VMEM_START, x, y);
    cpct_drawSprite(g_sprite_pong_title, pmem, G_SPRITE_PONG_TITLE_W, G_SPRITE_PONG_TITLE_H);
}

void _pong_sys_render_odyssey(u8 x, u8 y) {
    u8* pmem = cpct_getScreenPtr(CPCT_VMEM_START, x, y);
    u8  index = 0;
    while (index < 7) {
        cpct_drawSprite(odyssey[index], pmem, 4, 24);
        pmem += 4;
        ++index;
    }
}

void _pong_sys_render_menu(void) {
    _render_printMsg(
        "Q - move up", 
        PONG_WORLD_TO_SCREEN_X((i16) -256 * 2 * 7),
        PONG_WORLD_TO_SCREEN_Y((i16) 256 * 0),
        PONG_PEN
    );

    _render_printMsg(
        "A - move down", 
        PONG_WORLD_TO_SCREEN_X((i16) -256 * 2 * 7),
        PONG_WORLD_TO_SCREEN_Y((i16) 256 * 10),
        PONG_PEN
    );

    _render_printMsg(
        "PRESS ANY KEY TO START", 
        PONG_WORLD_TO_SCREEN_X((i16) -256 * 2 * 11),
        PONG_WORLD_TO_SCREEN_Y((i16) 256 * 30),
        PONG_PEN
    );

}
void pong_sys_render_init(void) {
    u8 x = PONG_WORLD_TO_SCREEN_X((i16) - (3.5 * PONG_WORLD_ODYSSEY_LETTER_WIDTH));
    u8 y = PONG_WORLD_TO_SCREEN_Y(- 2 * PONG_WORLD_ODYSSEY_LETTER_HEIGHT);
    _pong_sys_render_odyssey(x, y);
    while (x > PONG_WORLD_TO_SCREEN_X(PONG_WORLD_MIN_X + PONG_WORLD_ODYSSEY_LETTER_WIDTH)) {
        --x;
        cpct_waitHalts(10);
        cpct_waitVSYNC();
        _render_clearRoomTxt();
        _pong_sys_render_odyssey(x, y);
    };
    x = PONG_WORLD_TO_SCREEN_X((PONG_WORLD_MAX_X - PONG_PX_TO_WORLD(G_SPRITE_PONG_TITLE_W)) >> 1);
    _pong_sys_render_pong(x, y);

    _pong_sys_render_menu();
    sys_debug_waitKey();

    // _render_clearBox(
    //     PONG_SYS_RENDER_ENTITY_OFFSET_X,
    //     PONG_SYS_RENDER_ENTITY_OFFSET_Y,
    //     ROOM_TXT_BOX_W,
    //     ROOM_TXT_BOX_H
    // );
    _render_clearRoomTxt();
}