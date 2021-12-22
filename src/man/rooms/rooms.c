#include <cpctelera.h>
#include <man/rooms/rooms.h>

#include <sys/debug/debug.h>

const TRoom initial_rooms[ROOMS_MAX_ROOMS] = {
    {   // ROOM_INITIAL
        "Tu dormitorio",
        "Todo esta oscuro, no ves nada.          \xAEQue haces?",
        {{ NO_EXIT, NO_EXIT, NO_EXIT, NO_EXIT }}
    },
    {   // ROOM_ASEO_1 
        "Aseo principal", 
        "Te encuentras en el aseo principal de la casa.",
        {{ NO_EXIT, ROOM_PASILLO_1, NO_EXIT, NO_EXIT }}
    },
    {   // ROOM_PASI_1
        "Pasillo (ESTE)",
        "Lado ESTE del pasillo, nada de particular.",
        {{ ROOM_ASEO_1, ROOM_DORMITORIO_1, NO_EXIT, ROOM_PASILLO_2 }}
    },
    {   // ROOM_PASI_2
        "Pasillo (OESTE)",
        "Lado OESTE del pasillo, nada de particular.",
        {{ NO_EXIT, NO_EXIT, ROOM_PASILLO_1, NO_EXIT }}
    },
    {   // ROOM_DORM_1
        "Tu dormitorio",
        "Tu habitacion esta hecha un desastre, como siempre.",
        {{ ROOM_PASILLO_1, NO_EXIT, NO_EXIT, NO_EXIT }}
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

TRoom* man_rooms_setCurrentRoom(u8 index) {
    currentRoom = rooms;
    for(u8 i = index; i > 0; --i) {
        currentRoom++;
    }

    return currentRoom;
}