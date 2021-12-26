#include <man/game/game.h>

#include <man/prompt/prompt.h>
#include <man/history/history.h>
#include <sys/render/render.h>

void man_game_rendererConversational(void) {
    static TRoom* _lastRoom = 0;

    TRoom* room = man_rooms_getCurrentRoom();
    TPrompt* prompt = man_prompt_getPrompt();
    THistory* history = man_history_getHistoryPtr();

    sys_render_update(_game_action, room, history, prompt);
}