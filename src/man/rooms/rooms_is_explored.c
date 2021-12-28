#include <man/rooms/rooms.h>

u8 man_rooms_isExplored(TRoom *room) {
    if ((room->state & ROOM_STATE_EXPLORED) == ROOM_STATE_EXPLORED) {
        return 1;
    }
    return 0;
}