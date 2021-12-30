#include <man/rooms/rooms.h>

void man_rooms_unsetDark(TRoom *room) {
    room->state = room->state ^ ROOM_STATE_DARK;
}