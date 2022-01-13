#ifndef RESET_MAN_GAME
#define RESET_MAN_GAME

    #include <cpctelera.h>

    #include <sys/parser/parser.h>
    #include <man/rooms/rooms.h>
    #include <sys/render/render.h>
    
    #include <sys/debug/debug.h>

    #define KEY_DEL   (0x7F)
    #define KEY_ENTER (0x0D)

    #define MAX_OBJS_IN_ROOM  (3)

    typedef struct MsgStruct {
        u8* txt;
    } TMsgStruct;

    typedef void (*TActionRunnerFn)(TAction*, TRoom*);

// PRIVATE DATA
    extern TAction* _game_action;

// PRIVATE
    extern void _game_execute_action    (TAction *, TRoom *);

    extern void _game_action_drop       (TAction *, TRoom *);
    extern void _game_action_examine    (TAction *, TRoom *);
    extern void _game_action_go         (TAction *, TRoom *);
    extern void _game_action_inventory  (TAction *, TRoom *);
    extern void _game_action_search     (TAction *, TRoom *);
    extern void _game_action_take       (TAction *, TRoom *);
    extern void _game_action_turn_off   (TAction *, TRoom *);
    extern void _game_action_turn_on    (TAction *, TRoom *);
    extern void _game_action_unknown    (TAction *, TRoom *);
    extern void _game_action_use        (TAction *, TRoom *);

    extern void _game_playPong          (void);
    extern void _game_playBreakout      (void);

    extern u8   _game_show_objs_in_room (TRoom *);

// PUBLIC
    extern void man_game_init(void);
    extern void man_game_new(void);
    extern void man_game_input(void);
    extern void man_game_update(void);
    extern void man_game_render(void);

    // conversational game
//    extern void man_game_inputReaderConversational(void);
//    extern void man_game_updaterConversational(void);
//    extern void man_game_rendererConversational(void);

    // pong
    // extern void man_game_inputReaderPong(void);
    // extern void man_game_rendererPong(void);
    // extern void man_game_updaterPong(void);

#endif