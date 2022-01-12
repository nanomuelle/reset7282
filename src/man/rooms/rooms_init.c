#include <man/rooms/rooms.h>
#include <man/game/game.h>

#include <conversational/man/game/game.h>
#include <pong/man/game/game.h>
#include <breakout/man/game/game.h>

const TGameHandlers conversationalGame = {
    conversational_man_game_readInput,
    conversational_man_game_update,
    conversational_man_game_render,
};

const TGameHandlers pongGame = {
    pong_man_game_readInput,
    pong_man_game_update,
    pong_man_game_render,
    // man_game_inputReaderPong,
    // man_game_updaterPong,
    // man_game_rendererPong
};

const TGameHandlers breakoutGame = {
    breakout_man_game_readInput,
    breakout_man_game_update,
    breakout_man_game_render
};

const TRoom initial_rooms[ROOMS_MAX_ROOMS] = {
    {   ROOM_ID_DORMITORIO_1,
        "Tu dormitorio",
        "Todo esta hecho un desastre, como siempre.",
        "Despiertas pasadas unas horas.\x0dNo ves nada.\x0d\x0d\xAEQue haces?",
        {{ ROOM_ID_PASILLO_1, NO_EXIT, NO_EXIT, NO_EXIT }},
        ROOM_STATE_DEFAULT | ROOM_STATE_DARK,
        &conversationalGame,
    },
    {   ROOM_ID_INVENTARIO, // not a real room, es el almacén de objetos que tiene el usuario
        "",
        "",
        "",
        {{ NO_EXIT, NO_EXIT, NO_EXIT, NO_EXIT }},
        ROOM_STATE_DEFAULT | ROOM_STATE_EXPLORED,
        0x00, // no game handlers
    },
    {   ROOM_ID_ASEO_1, 
        "Aseo principal", 
        "Te encuentras en el aseo principal de la casa.",
        "No ves nada",
        {{ NO_EXIT, ROOM_ID_PASILLO_1, NO_EXIT, NO_EXIT }},
        ROOM_STATE_DEFAULT,
        &conversationalGame,
    },
    {   ROOM_ID_PASILLO_1,
        "Pasillo (OESTE)",
        "Lado OESTE del pasillo, nada de particular.",
        "No ves nada",
        {{ ROOM_ID_ASEO_1, ROOM_ID_DORMITORIO_1, ROOM_ID_PASILLO_2, NO_EXIT }},
        ROOM_STATE_DEFAULT,
        &conversationalGame,
    },
    {   ROOM_ID_PASILLO_2,
        "Pasillo (ESTE)",
        "Lado ESTE del pasillo, nada de particular.",
        "No ves nada",
        {{ ROOM_ID_DORMITORIO_3, ROOM_ID_DORMITORIO_2, NO_EXIT, ROOM_ID_PASILLO_1 }},
        ROOM_STATE_DEFAULT,
        &conversationalGame,
    },
    {   ROOM_ID_PONG,
        "Consola MagnaVox Odyssey",
        "",
        "",
        {{ NO_EXIT, NO_EXIT, NO_EXIT, NO_EXIT }},
        ROOM_STATE_DEFAULT,
        &pongGame,
    },
    {   ROOM_ID_DORMITORIO_2,
        "Dormitorio hermana",
        "Tu hermana juega tranquilamente a reyes y princesas con un juego de te.",
        "Tu hermana se pone a gritar para que enciendas de nuevo.",
        {{ ROOM_ID_PASILLO_2, NO_EXIT, NO_EXIT, NO_EXIT }},
        ROOM_STATE_DEFAULT,
        &conversationalGame,
    },
    {   ROOM_ID_DORMITORIO_3,
        "Dormitorio padres",
        "Tus padres duermen placidamente, parece que no se han despertado",
        "Tus padres duermen placidamente. La luz esta apagada.",
        {{ NO_EXIT, ROOM_ID_PASILLO_2, ROOM_ID_ASEO_2, NO_EXIT }},
        ROOM_STATE_DEFAULT | ROOM_STATE_DARK,
        &conversationalGame,
    },
    {   ROOM_ID_ASEO_2, 
        "Aseo del dormitorio", 
        "Te encuentras en el aseo del dormitorio. Esta en obras.",
        "No ves nada",
        {{ NO_EXIT, NO_EXIT, NO_EXIT, ROOM_ID_DORMITORIO_3 }},
        ROOM_STATE_DEFAULT,
        &conversationalGame,
    },
    {   ROOM_ID_BREAKOUT,
        "Breakout",
        "",
        "",
        {{ NO_EXIT, NO_EXIT, NO_EXIT, NO_EXIT }},
        ROOM_STATE_DEFAULT | ROOM_STATE_DARK,
        &breakoutGame,
    }
};

void man_rooms_init() {
    cpct_memcpy(_rooms, initial_rooms, ROOMS_MAX_ROOMS * sizeof(TRoom));
    _currentRoom = 0;
    _lastRoom = 0;
}