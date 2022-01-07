#include <pong/sys/render/render.h>
#include <sys/render/render.h>

#include <assets/odys.h>
#include <assets/pong.h>
#include <pong/pong.h>

// const u8* const g_odyssey[9] = {
const u8* const odyssey[] = {
    g_tile_odys_0, // O
    g_tile_odys_1, // D
    g_tile_odys_2, // Y
    g_tile_odys_3, // S
    g_tile_odys_3, // S
    g_tile_odys_4, // E
    g_tile_odys_2, // Y
};

void _pong_sys_render_pong(u8 x, u8 y) {
    u8* pmem = cpct_getScreenPtr(CPCT_VMEM_START, x, y);
    cpct_drawSprite(g_tile_pong, pmem, G_TILE_PONG_W, G_TILE_PONG_H);
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
        WORLD_TO_SCREEN_X((i16) -256 * 2 * 7),
        WORLD_TO_SCREEN_Y((i16) 256 * 0),
        1
    );

    _render_printMsg(
        "A - move down", 
        WORLD_TO_SCREEN_X((i16) -256 * 2 * 7),
        WORLD_TO_SCREEN_Y((i16) 256 * 10),
        1
    );

    _render_printMsg(
        "PRESS ANY KEY TO START", 
        WORLD_TO_SCREEN_X((i16) -256 * 2 * 11),
        WORLD_TO_SCREEN_Y((i16) 256 * 30),
        1
    );

}
void pong_sys_render_init(void) {
    u8 x = WORLD_TO_SCREEN_X((i16) - (3.5 * PONG_WORLD_ODYSSEY_LETTER_WIDTH));
    u8 y = WORLD_TO_SCREEN_Y(- 2 * PONG_WORLD_ODYSSEY_LETTER_HEIGHT);
    _pong_sys_render_odyssey(x, y);
    while (x > WORLD_TO_SCREEN_X(PONG_WORLD_MIN_X + PONG_WORLD_ODYSSEY_LETTER_WIDTH)) {
        --x;
        cpct_waitHalts(10);
        cpct_waitVSYNC();
        _render_clearRoomTxt();
        _pong_sys_render_odyssey(x, y);
    };
    x = WORLD_TO_SCREEN_X((PONG_WORLD_MAX_X - PONG_PX_TO_WORLD(G_TILE_PONG_W)) / 2);
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