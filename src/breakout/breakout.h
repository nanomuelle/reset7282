#pragma once

#include <cpctelera.h>
#include <globals.h>

#include <eng/eng.h>
#include <breakout/sys/collisions/collisions.h>
#include <breakout/sys/ai/ai.h>

#include <assets/breakout_medium_brick_m1.h>
#include <assets/breakout_paddel_m1.h>
#include <assets/breakout_ball_m1.h>
#include <assets/breakout_bg.h>

typedef enum BreakoutEntityIdEnum {
    BRK_ENTITY_ID_NULL = 0,
    BRK_ENTITY_ID_BALL,
    BRK_ENTITY_ID_PADDEL,
    BRK_ENTITY_ID_BRICK,
} TBreakoutEntityId;

// BALL ENTITY
#define BREAKOUT_WORLD_BALL_W       ( EPS_PX_TO_WORLD(ERS_BYTES_TO_PX(G_SPR_BRK_BALL_M1_0_W - 1)))
#define BREAKOUT_WORLD_BALL_H       ( EPS_PX_TO_WORLD(G_SPR_BRK_BALL_M1_0_H))
#define BREAKOUT_WORLD_BALL_X       ( EPS_WORLD_MAX_X / 2 )
#define BREAKOUT_WORLD_BALL_Y       ( EPS_WORLD_MAX_Y - 5 * BREAKOUT_WORLD_BALL_H )
#define BREAKOUT_WORLD_BALL_VX      ((i16) EPS_PX_TO_WORLD(1))
#define BREAKOUT_WORLD_BALL_VY      ((i16) EPS_PX_TO_WORLD(2))

#define BREAKOUT_WORLD_BALL_MAX_VX  ((i16) BREAKOUT_WORLD_BALL_W - 1 )
#define BREAKOUT_WORLD_BALL_MAX_VY  ((i16) BREAKOUT_WORLD_BALL_H - 1 )

// PADDEL ENTITY
#define BREAKOUT_WORLD_PADDEL_W     ( EPS_PX_TO_WORLD(ERS_BYTES_TO_PX(G_SPR_BRK_PADDEL_M1_0_W - 1)))
#define BREAKOUT_WORLD_PADDEL_H     ( EPS_PX_TO_WORLD(G_SPR_BRK_PADDEL_M1_0_H))
#define BREAKOUT_WORLD_PADDEL_VX    ((i16) EPS_PX_TO_WORLD(3) )
#define BREAKOUT_WORLD_PADDEL_VY    ((i16)  0  )
#define BREAKOUT_WORLD_PADDEL_X     ( (EPS_WORLD_MAX_X + BREAKOUT_WORLD_PADDEL_W) / 2 )
#define BREAKOUT_WORLD_PADDEL_Y     ( EPS_WORLD_MAX_Y - 1.5 * BREAKOUT_WORLD_PADDEL_H )

// BRICK ENTITY
#define BRK_BRICK_WORLD_W (EPS_PX_TO_WORLD(ERS_BYTES_TO_PX(G_SPR_BRK_BRICK_M1_0_W - 1)))
#define BRK_BRICK_WORLD_H (EPS_PX_TO_WORLD(G_SPR_BRK_BRICK_M1_0_H) )

// BRICKS ZONE BOUNDING BOX (used to quick discard collisions)
#define BRK_WORLD_BRICKS_X1         ( 4 * BRK_BRICK_WORLD_W )
#define BRK_WORLD_BRICKS_X2         ( BRK_WORLD_BRICKS_X1 + (8 * BRK_BRICK_WORLD_W) )
#define BRK_WORLD_BRICKS_Y1         ( 4 * BRK_BRICK_WORLD_H )
#define BRK_WORLD_BRICKS_Y2         ( BRK_WORLD_BRICKS_Y1 + (4 * BRK_BRICK_WORLD_H) )

// PLAY ZONE LIMITS
#define BRK_LIMIT_LEFT   ( EPS_PX_TO_WORLD(16) )
#define BRK_LIMIT_TOP    ( EPS_PX_TO_WORLD(16) )
#define BRK_LIMIT_RIGHT  ( EPS_WORLD_MAX_X - EPS_PX_TO_WORLD(ERS_BYTES_TO_PX(G_SPR_BRK_BG_0_W) ))
#define BRK_LIMIT_BOTTOM ( EPS_WORLD_MAX_Y - EPS_PX_TO_WORLD(G_SPR_BRK_BALL_M1_0_H) )
