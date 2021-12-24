#include <cpctelera.h>

#include <man/game/game.h>
#include <man/history/history.h>

void _game_action_inventory(TAction* action, TRoom* room) {
    TRoom *inventory = man_rooms_getRoom(ROOM_ID_INVENTARIO);
    u8 count = _game_show_objs_in_room(inventory);
    if (count == 0) {
        man_history_addResponse("no tienes nada");
    }
}