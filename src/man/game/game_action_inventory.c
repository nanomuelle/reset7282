#include <cpctelera.h>

#include <man/game/game.h>
#include <man/history/history.h>

void _game_action_inventory(TAction* action, TRoom* room) {
    u8 count = _game_show_objs_in_room(ROOM_ID_INVENTARIO);
    if (count == 0) {
        man_history_addWarning("-> no tienes nada");
    }
}