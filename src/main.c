// //-----------------------------LICENSE NOTICE------------------------------------
// //  This file is part of CPCtelera: An Amstrad CPC Game Engine
// //  Copyright (C) 2018 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
// //
// //  This program is free software: you can redistribute it and/or modify
// //  it under the terms of the GNU Lesser General Public License as published by
// //  the Free Software Foundation, either version 3 of the License, or
// //  (at your option) any later version.
// //
// //  This program is distributed in the hope that it will be useful,
// //  but WITHOUT ANY WARRANTY; without even the implied warranty of
// //  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// //  GNU Lesser General Public License for more details.
// //
// //  You should have received a copy of the GNU Lesser General Public License
// //  along with this program.  If not, see <http://www.gnu.org/licenses/>.
// //------------------------------------------------------------------------------

// #include <cpctelera.h>
// #include <keyboard/keyboard.h>

// #define PROMPT_X 1
// #define PROMPT_Y 190
// #define PROMPT_CHAR '>'
// #define PROMPT_CURSOR 0x8F
// #define CHAR_SPACING 2 // BYTES

// void printMsg(const char* string, u8 x, u8 y) {
//    u8* pvmem;  // Pointer to video memory

//    // Make pvmem point to the byte in video memory where we want
//    // to print our string (coordinates (20, 96) in bytes, (80, 96) in pixels,
//    // as each byte is 4 pixels wide in mode 1)
//    pvmem = cpct_getScreenPtr(CPCT_VMEM_START, x, y);
//    // Set Mode 1 Character&String drawing functions to use colours 
//    // 1 (yellow) for foreground and 0 (blue) for background
//    cpct_setDrawCharM1(1, 0);
//    // Draw the actual string where pvmem is pointing
//    cpct_drawStringM1(string, pvmem);
// }

// void printChar(u16 ascii, u8 x, u8 y) {
//    u8* pvmem;  // Pointer to video memory

//    // Make pvmem point to the byte in video memory where we want
//    // to print our string (coordinates (20, 96) in bytes, (80, 96) in pixels,
//    // as each byte is 4 pixels wide in mode 1)
//    pvmem = cpct_getScreenPtr(CPCT_VMEM_START, x, y);
//    // Set Mode 1 Character&String drawing functions to use colours 
//    // 1 (yellow) for foreground and 0 (blue) for background
//    cpct_setDrawCharM1(1, 0);
//    // Draw the actual string where pvmem is pointing
//    cpct_drawCharM1(pvmem, ascii);
// }

// void readInput(u8 x, u8 y) {
//     u8 current_x = x;
//     printChar(PROMPT_CURSOR, current_x, y);
//     while (1) {
//         u8 key = reset_waitKey();
//         if (key == 0x0D) {
//             return;
//         }

//         printChar(key, current_x, y);
//         current_x += CHAR_SPACING; // inc 2 bytes (8px in mode 1)
//         printChar(PROMPT_CURSOR, current_x, y);
//     };
// }

// void __main(void) {
//     printMsg("Por fin abres los ojos pero no puedes   ver absolutamente nada.", 0, 96);
//     printMsg("\xAEQue haces?", 0, 96 + 24);

//     // print prompt
//     printChar(PROMPT_CHAR, 1, 190);
//     readInput(PROMPT_X + CHAR_SPACING + 1, PROMPT_Y);

//     printMsg("Bye!", 20, 126);
// }

#include <man/game/game.h>

void main(void) {
    man_game_init();
    man_game_new();
    man_game_render();

    while(1) {
        man_game_input();
        man_game_update();
        man_game_render();
    }
}