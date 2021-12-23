#include <man/rooms/rooms.h>
#include <man/prompt/prompt.h>
#include <sys/render/render.h>

void man_game_render(void) {
    static TRoom* lastRoom = 0x0000;

    TRoom* room = man_rooms_getCurrentRoom();
    TPrompt* prompt = man_prompt_getPrompt();
    THistory* history = man_history_getHistoryPtr();

    if (room != lastRoom) {
        sys_render_clearScreen();
        lastRoom = room;
    }

    sys_render_renderRoom(room);
    sys_render_renderHistory(history);
    sys_render_renderPrompt(prompt);
}
