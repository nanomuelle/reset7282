#include <sys/render/render.h>

void sys_render_update(TAction *action, TRoom *room, THistory *history, TPrompt *prompt) {
    static TRoom* _lastRoom = 0;
    
    if (_lastRoom != room) {
        _render_clearRoom(action);
        _lastRoom = room;
    }
    _render_updateRoom(room);
    _render_updateHistory(history);
    sys_render_updatePrompt(prompt);
}