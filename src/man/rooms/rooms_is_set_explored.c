#include <man/rooms/rooms.h>

void man_rooms_setExplored(TRoom *room) {
    room->state = room->state | ROOM_STATE_EXPLORED;
}