#include <sys/render/render.h>

void sys_render_update(TAction *action, TRoom *room, THistory *history, TPrompt *prompt) {
    TRoom* lastRoom = man_rooms_getLastRoom();

    if (lastRoom != room) {
        sys_render_clearRoom(action);
    }

    _render_updateRoom(room);
    _render_updateHistory(history);
    sys_render_updatePrompt(prompt);

    _render_printObjsInInventory();
}