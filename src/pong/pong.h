#pragma once

#include <globals.h>
#include <eng/eng.h>

#include <assets/pong_ball_m1.h>
#include <assets/pong_paddel_m1.h>
#include <assets/pong_odyse.h>

// FOREGROUND PEN FOR ALL
#define PONG_PEN 3

// ODYSSEY TITLE
#define PONG_WORLD_ODYSSEY_LETTER_WIDTH     ((i16) EPS_PX_TO_WORLD(ERS_BYTES_TO_PX(4)))
#define PONG_WORLD_ODYSSEY_LETTER_HEIGHT    ((i16) EPS_PX_TO_WORLD(24))

// ENTITIES
typedef enum PongEntityIdEnum {
    PONG_ENTITY_ID_NULL = 0,
    PONG_ENTITY_ID_BALL,
    PONG_ENTITY_ID_LEFT_PADDEL,
    PONG_ENTITY_ID_RIGHT_PADDEL
} TPongEntityId;

#define PONG_WORLD_PADDEL_W       ( EPS_PX_TO_WORLD( ERS_BYTES_TO_PX(G_SPR_PONG_PADDEL_M1_0_W - 1) ) )
#define PONG_WORLD_PADDEL_H       ( EPS_PX_TO_WORLD( G_SPR_PONG_PADDEL_M1_0_H ) )

#define PONG_WORLD_PADDEL_VX      ( 0 )
#define PONG_WORLD_PADDEL_VY      ( 350 )

#define PONG_WORLD_LEFT_PADDEL_X  ( EPS_PX_TO_WORLD( 8 ) )
#define PONG_WORLD_LEFT_PADDEL_Y  ( EPS_WORLD_MAX_Y / 2 )

#define PONG_WORLD_RIGHT_PADDEL_X ( EPS_WORLD_MAX_X - PONG_WORLD_PADDEL_W - EPS_PX_TO_WORLD( 8) )
#define PONG_WORLD_RIGHT_PADDEL_Y ( EPS_WORLD_MAX_Y / 2 )

// BALL
#define PONG_BALL_WORLD_MAX_VX  ((i16)  EPS_PX_TO_WORLD(2) )
#define PONG_BALL_WORLD_MIN_VX  ((i16) -EPS_PX_TO_WORLD(2) )
#define PONG_BALL_WORLD_MAX_VY  ((i16)  EPS_PX_TO_WORLD(2) )
#define PONG_BALL_WORLD_MIN_VY  ((i16) -EPS_PX_TO_WORLD(2) )

#define PONG_BALL_WORLD_IVX     ( 5 )
#define PONG_POINTS_TO_WIN      ( 3 )
