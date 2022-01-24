#include "eem.h"

TEEM_entity  m_eem_buffer[EEM_BUFFER_SIZE];
TEEM_state   m_eem_buffer_eof;         // marca de final del buffer
u8           m_eem_num_valid_entities; // num of valid entities
TEEM_entity* m_eem_next_free;          // ptr to the next free entity
u8           m_eem_needs_update;       // flag: 1.- needs update, 0.- do not needs update

//
// CASE 1: COLLISION
//
//  E1 E2 E3 E4
//  E6 E7 E8 E9
//         B
//
//   P
// ------------
//
// [P][B][E6][E7][E8][E9][E1][E2][E3][E4][E5][f][.]
//
// collision B vs E8
// - kill   E8 (k)
// - redraw E9 (r)
//                 k   r
// [P][B][E6][E7][E8][E9][E1][E2][E3][E4][E5][f][.]
//
// render (draw and remove r mark)
//                 k
// [P][B][E6][E7][E8][E9][E1][E2][E3][E4][E5][f][.]
//
// update entities
//                 k
// [P][B][E6][E7][E8][E9][E1][E2][E3][E4][E5][f][.]
//
// [P][B][E6][E7][E9][E1][E2][E3][E4][E5][f][.][.]

//
// CASE 2: RESORT - BALL MOVES BETWEEN BRICKS
//
//  E1 E2 E3 E4     E1 E2 E3 E4
//  E6 E7    E9     E6 E7  B E9
//           B  ->
//   P               P
// ------------    ------------
// before          after
//
// before [P ][B ][E6][E7][E9][E1][E2][E3][E4][E5][f][.][.]
//
//            |---------v
//        [P ][B ][E6][E7][E9][E1][E2][E3][E4][E5][f][.][.]
//        [P ][E6][E7][B ][E9][E1][E2][E3][E4][E5][f][.][.]
//
