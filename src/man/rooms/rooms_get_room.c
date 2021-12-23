#include <man/rooms/rooms.h>

TRoom * man_rooms_getRoom(TRoomIdEnum id) {
    TRoom *room = man_rooms_getRoomsPtr();

    while (room->id != id) {
        ++room;
    }

    return room;
}