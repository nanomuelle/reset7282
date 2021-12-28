#include <man/rooms/rooms.h>
#include <man/game/game.h>

const TRoom initial_rooms[ROOMS_MAX_ROOMS] = {
    {   ROOM_ID_INITIAL,
        "Tu dormitorio",
        "Despiertas pasadas unas horas.\x0dNo ves nada.\x0d\x0d\xAEQue haces?",
        {{ NO_EXIT, NO_EXIT, NO_EXIT, NO_EXIT }},
        ROOM_STATE_DEFAULT | ROOM_STATE_DARK,
        man_game_rendererConversational,
        man_game_updaterConversational,
        man_game_inputReaderConversational
    },
    {   // not a real room, es el almacén de objetos que tiene el usuario
        ROOM_ID_INVENTARIO,
        "",
        "",
        {{ NO_EXIT, NO_EXIT, NO_EXIT, NO_EXIT }},
        ROOM_STATE_DEFAULT | ROOM_STATE_EXPLORED,
        0x00, // no renderer
        0x00, // no updater
        0x00, // no input reader
    },
    {   ROOM_ID_ASEO_1, 
        "Aseo principal", 
        "Te encuentras en el aseo principal de la casa.",
        {{ NO_EXIT, ROOM_ID_PASILLO_1, NO_EXIT, NO_EXIT }},
        ROOM_STATE_DEFAULT,
        man_game_rendererConversational,
        man_game_updaterConversational,
        man_game_inputReaderConversational
    },
    {   ROOM_ID_PASILLO_1,
        "Pasillo (ESTE)",
        "Lado ESTE del pasillo, nada de particular.",
        {{ ROOM_ID_ASEO_1, ROOM_ID_DORMITORIO_1, NO_EXIT, ROOM_ID_PASILLO_2 }},
        ROOM_STATE_DEFAULT,
        man_game_rendererConversational,
        man_game_updaterConversational,
        man_game_inputReaderConversational
    },
    {   ROOM_ID_PASILLO_2,
        "Pasillo (OESTE)",
        "Lado OESTE del pasillo, nada de particular.",
        {{ NO_EXIT, NO_EXIT, ROOM_ID_PASILLO_1, NO_EXIT }},
        ROOM_STATE_DEFAULT,
        man_game_rendererConversational,
        man_game_updaterConversational,
        man_game_inputReaderConversational
    },
    {   ROOM_ID_DORMITORIO_1,
        "Tu dormitorio",
        "Tu habitacion esta hecha un desastre, como siempre.",
        {{ ROOM_ID_PASILLO_1, NO_EXIT, NO_EXIT, NO_EXIT }},
        ROOM_STATE_DEFAULT,
        man_game_rendererConversational,
        man_game_updaterConversational,
        man_game_inputReaderConversational
    },
    {
        ROOM_ID_PONG,
        "Consola MagnaVox Odyssey",
        "",
        {{ NO_EXIT, NO_EXIT, NO_EXIT, NO_EXIT }},
        ROOM_STATE_DEFAULT | ROOM_STATE_DARK,
        man_game_rendererPong,
        man_game_updaterPong,
        man_game_inputReaderPong
    }
};

void man_rooms_init() {
    cpct_memcpy(_rooms, initial_rooms, ROOMS_MAX_ROOMS * sizeof(TRoom));
    _currentRoom = _rooms;
}