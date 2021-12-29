#include <man/rooms/rooms.h>

TRoom* man_rooms_setCurrentRoom(TRoomIdEnum roomId) {
    TRoom* rooms = man_rooms_getRoomsPtr();

    // TODO evitar bucle infinito en caso de que roomId no exista
    while(rooms->id != roomId) ++rooms;
    _lastRoom = _currentRoom;
    _currentRoom = rooms;
    return rooms;
}