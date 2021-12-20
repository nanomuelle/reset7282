#ifndef RESET_MAN_GAME
#define RESET_MAN_GAME
    #include <cpctelera.h>
    
    #define KEY_DEL  0x7F
    #define KEY_ENTER 0x0D

    extern void man_game_init(void);
    extern void man_game_new(void);
    extern void man_game_input(void);
    extern void man_game_update(void);
    extern void man_game_render(void);
#endif