#include <sys/render/render.h>

void sys_render_update(TAction *action, TRoom *room, THistory *history, TPrompt *prompt) {
    static TRoom* _lastRoom = 0;

    if (_lastRoom != room) {
        sys_render_clearRoom(action);
        _lastRoom = room;
    }
    _render_updateRoom(room);
    _render_updateHistory(history);
    sys_render_updatePrompt(prompt);

    // obs en inventario
    {
        TRoom *inventory = man_rooms_getRoom(ROOM_ID_INVENTARIO);
        u8 *pmem = cpct_getScreenPtr(CPCT_VMEM_START, PROMPT_X, PROMPT_Y + 12);
        u8 c = cpct_px2byteM1(2, 2, 0, 0);
        cpct_memset(pmem, c, 80);

        _render_printObjsInRoom(inventory, 79, PROMPT_Y + 14);
    }
}