#include <breakout/breakout.h>

//
// TODO: no modificar directamente la v de la ball
//       solo marcar que hay que hacer un split en vx o vy
//       y al final de la comprobación de colisiones hacer el flip
//       Porque si se hace durante, la v que se comprueba de una 
//       a entidad a otra es diferente provocando rebotes extraños
//
void breakout_man_game_update(void) {
    breakout_sys_ai_update();           // ai system
    eps_update();                       // physics system
    breakout_sys_collisions_update();   // collision system update
    // _breakout_man_game_checkCollisions(); // collisions
}