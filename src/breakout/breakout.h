#pragma once

#include <cpctelera.h>
#include <globals.h>
#include <assets/breakout_medium_brick.h>
#include <assets/breakout_paddel.h>
#include <assets/breakout_ball.h>

// WORLD
#define BREAKOUT_PX_TO_WORLD(px)    ( px << 8 ) // PX TO PHYSICS UNITS

#define BREAKOUT_WORLD_W            ((i16) BREAKOUT_PX_TO_WORLD( ROOM_TXT_BOX_W ) )
#define BREAKOUT_WORLD_H            ((i16) BREAKOUT_PX_TO_WORLD( ROOM_TXT_BOX_H ) )

#define BREAKOUT_WORLD_MIN_X        ((i16) (-BREAKOUT_WORLD_W >> 1) + BREAKOUT_PX_TO_WORLD(1) )
#define BREAKOUT_WORLD_MAX_X        ((i16) ( BREAKOUT_WORLD_W >> 1) - BREAKOUT_PX_TO_WORLD(1) )
#define BREAKOUT_WORLD_MIN_Y        ((i16) (-BREAKOUT_WORLD_H >> 1) + BREAKOUT_PX_TO_WORLD(2) )
#define BREAKOUT_WORLD_MAX_Y        ((i16) ( BREAKOUT_WORLD_H >> 1) + BREAKOUT_PX_TO_WORLD(1) )

// ENTITIES
#define BREAKOUT_MAN_ENTITY_BUFFER_SIZE 46

typedef enum BreakoutEntityIdEnum {
    BREAKOUT_ENTITY_ID_NULL = 0,
    BREAKOUT_ENTITY_ID_BALL,
    BREAKOUT_ENTITY_ID_PADDEL,
    BREAKOUT_ENTITY_ID_BRICK,
} TBreakoutEntityId;

// BALL ENTITY
#define BREAKOUT_WORLD_BALL_W       ( BREAKOUT_PX_TO_WORLD(1) )
#define BREAKOUT_WORLD_BALL_H       ( BREAKOUT_PX_TO_WORLD(4) )
#define BREAKOUT_WORLD_BALL_X       ( BREAKOUT_WORLD_BALL_H >> 1 )
#define BREAKOUT_WORLD_BALL_Y       ( 20 * 256 )
#define BREAKOUT_WORLD_BALL_VX      (  64 )
#define BREAKOUT_WORLD_BALL_VY      ( -500 )
#define BREAKOUT_WORLD_BALL_MIN_VX  ( -BREAKOUT_PX_TO_WORLD(2) )
#define BREAKOUT_WORLD_BALL_MIN_VY  ( -BREAKOUT_PX_TO_WORLD(3) )
#define BREAKOUT_WORLD_BALL_MAX_VX  ( BREAKOUT_PX_TO_WORLD(1) )
#define BREAKOUT_WORLD_BALL_MAX_VY  ( BREAKOUT_PX_TO_WORLD(2) )

// PADDEL ENTITY
#define BREAKOUT_WORLD_PADDEL_W     ( BREAKOUT_PX_TO_WORLD(G_SPRITE_BREAKOUT_PADDEL_W) )
#define BREAKOUT_WORLD_PADDEL_H     ( BREAKOUT_PX_TO_WORLD(G_SPRITE_BREAKOUT_PADDEL_H) )
#define BREAKOUT_WORLD_PADDEL_VX    ( 200 )
#define BREAKOUT_WORLD_PADDEL_VY    ( 0 )
#define BREAKOUT_WORLD_PADDEL_X     ( 0 ) // BREAKOUT_WORLD_PADDEL_W >> 1 )
#define BREAKOUT_WORLD_PADDEL_Y     ( BREAKOUT_WORLD_MAX_Y - BREAKOUT_WORLD_PADDEL_H )

// BRICKS
#define BREAKOUT_WORLD_BRICK_W ( BREAKOUT_PX_TO_WORLD(G_SPRITE_BREAKOUT_MEDIUM_BRICK_W) )
#define BREAKOUT_WORLD_BRICK_H ( BREAKOUT_PX_TO_WORLD(G_SPRITE_BREAKOUT_MEDIUM_BRICK_H) )
