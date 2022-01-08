#include <man/rooms/rooms.h>

void man_rooms_switchDark(TRoom *room) {
    room->state ^= ROOM_STATE_DARK;
}