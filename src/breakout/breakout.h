#pragma once

#include <cpctelera.h>
#include <globals.h>

#include <eng/eng.h>
#include <console/console.h>

#include <assets/breakout_medium_brick_m1.h>
#include <assets/breakout_paddel.h>
#include <assets/breakout_ball_m1.h>

typedef enum BreakoutEntityIdEnum {
    BREAKOUT_ENTITY_ID_NULL = 0,
    BREAKOUT_ENTITY_ID_BALL,
    BREAKOUT_ENTITY_ID_PADDEL,
    BREAKOUT_ENTITY_ID_BRICK,
} TBreakoutEntityId;

// BALL ENTITY
#define BREAKOUT_WORLD_BALL_W       ( CSP_PX_TO_WORLD(G_SPR_BRK_BALL_M1_0_W - 1))
#define BREAKOUT_WORLD_BALL_H       ( CSP_PX_TO_WORLD(G_SPR_BRK_BALL_M1_0_H))
#define BREAKOUT_WORLD_BALL_X       ( CSP_WORLD_W / 2 )
#define BREAKOUT_WORLD_BALL_Y       ( 20 * 256 )
#define BREAKOUT_WORLD_BALL_VX      (  48 )
#define BREAKOUT_WORLD_BALL_VY      ( -300 )
#define BREAKOUT_WORLD_BALL_MIN_VX  ( -CSP_PX_TO_WORLD(2) )
#define BREAKOUT_WORLD_BALL_MIN_VY  ( -CSP_PX_TO_WORLD(3) )
#define BREAKOUT_WORLD_BALL_MAX_VX  ( CSP_PX_TO_WORLD(2) )
#define BREAKOUT_WORLD_BALL_MAX_VY  ( CSP_PX_TO_WORLD(3) )

// PADDEL ENTITY
#define BREAKOUT_WORLD_PADDEL_W     ( CSP_PX_TO_WORLD(G_SPR_BRK_PADDEL_W) )
#define BREAKOUT_WORLD_PADDEL_H     ( CSP_PX_TO_WORLD(G_SPR_BRK_PADDEL_H) )
#define BREAKOUT_WORLD_PADDEL_VX    ( 200 )
#define BREAKOUT_WORLD_PADDEL_VY    ( 0 )
#define BREAKOUT_WORLD_PADDEL_X     ( 0 ) // BREAKOUT_WORLD_PADDEL_W >> 1 )
#define BREAKOUT_WORLD_PADDEL_Y     ( CSP_WORLD_MAX_Y - BREAKOUT_WORLD_PADDEL_H )
