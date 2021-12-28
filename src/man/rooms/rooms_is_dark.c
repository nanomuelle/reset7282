#include <man/rooms/rooms.h>

u8 man_rooms_isDark(TRoom *room) {
    if ((room->state & ROOM_STATE_DARK) == ROOM_STATE_DARK) {
        return 1;
    }
    return 0;
}