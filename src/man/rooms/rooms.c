#include <cpctelera.h>
#include <man/rooms/rooms.h>

const TRoom initial_rooms[ROOMS_MAX_ROOMS] = {
    {   // ROOM_ASEO_1 
        "Aseo principal\0", 
        "Te encuentras en el aseo principal de la casa.\0",
        {{ NO_EXIT, ROOM_PASI_1, NO_EXIT, NO_EXIT }}
    },
    {   // ROOM_PASI_1
        "Pasillo (ESTE)\0",
        "Lado este del pasillo, nada de particular.\0",
        {{ ROOM_ASEO_1, ROOM_DORM_1, NO_EXIT, NO_EXIT }}
    },
    {   // ROOM_DORM_1
        "Tu dormitorio\0",
        "Tu habitacion esta hecha un desastre, como siempre.\0",
        {{ ROOM_PASI_1, NO_EXIT, NO_EXIT, NO_EXIT }}
    }
};

TRoom rooms[ROOMS_MAX_ROOMS];
TRoom* currentRoom;

void man_rooms_init() {
    cpct_memcpy(rooms, initial_rooms, ROOMS_MAX_ROOMS * sizeof(TRoom));
    currentRoom = rooms;
}

TRoom* man_rooms_getCurrentRoom() {
    return currentRoom;
}

void man_rooms_setCurrentRoom(u8 index) {
    currentRoom = rooms + index;
}