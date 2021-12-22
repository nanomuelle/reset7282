#ifndef RESET_MAN_GAME
#define RESET_MAN_GAME

    #include <cpctelera.h>
    #include <sys/parser/parser.h>
    #include <man/rooms/rooms.h>

    #define KEY_DEL   0x7F
    #define KEY_ENTER 0x0D

    typedef void (*TActionRunner)(TAction*, TRoom*);

// PRIVATE
    extern void _game_execute_action(TAction *, TRoom *);

    extern void _game_action_go(TAction *, TRoom *);
    extern void _game_action_search(TAction *, TRoom *);
    extern void _game_action_turn_on(TAction *, TRoom *);
    extern void _game_action_unknown(TAction *, TRoom *);

// PUBLIC
    extern void man_game_init(void);
    extern void man_game_new(void);
    extern void man_game_input(void);
    extern void man_game_update(void);
    extern void man_game_render(void);
#endif