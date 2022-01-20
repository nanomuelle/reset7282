#pragma once

#include <globals.h>
#include <console/man/entity/entity.h>
#include <console/sys/physics/physics.h>
#include <console/sys/render/render.h>

// FOREGROUND PEN FOR ALL
#define PONG_PEN 3

// WORLD
// #define CSP_PX_TO_WORLD(px)    ( px << 8 ) // PX TO PHYSICS UNITS

// #define PONG_WORLD_W            ((i16) CSP_PX_TO_WORLD( ROOM_TXT_BOX_W ) )
// #define PONG_WORLD_H            ((i16) CSP_PX_TO_WORLD( ROOM_TXT_BOX_H ) )

// #define PONG_WORLD_MIN_X        ((i16) ((-PONG_WORLD_W >> 1) + CSP_PX_TO_WORLD(1)) )
// #define PONG_WORLD_MAX_X        ((i16) (( PONG_WORLD_W >> 1) - CSP_PX_TO_WORLD(1)) )
// #define PONG_WORLD_MIN_Y        ((i16) ((-PONG_WORLD_H >> 1) + CSP_PX_TO_WORLD(2)) )
// #define PONG_WORLD_MAX_Y        ((i16) (( PONG_WORLD_H >> 1) - CSP_PX_TO_WORLD(2)) )

// ODYSSEY TITLE

#define PONG_WORLD_ODYSSEY_LETTER_WIDTH     ((i16) CSP_PX_TO_WORLD( 4)) // 16 PX = 4 bytes
#define PONG_WORLD_ODYSSEY_LETTER_HEIGHT    ((i16) CSP_PX_TO_WORLD(24))

// ENTITIES
typedef enum PongEntityIdEnum {
    PONG_ENTITY_ID_NULL = 0,
    PONG_ENTITY_ID_BALL,
    PONG_ENTITY_ID_LEFT_PADDEL,
    PONG_ENTITY_ID_RIGHT_PADDEL
} TPongEntityId;

#define PONG_WORLD_PADDEL_W     ( CSP_PX_TO_WORLD(1) )
#define PONG_WORLD_PADDEL_H     ( CSP_PX_TO_WORLD(16) )

#define PONG_WORLD_PADDEL_VX      ( 0 )
#define PONG_WORLD_PADDEL_VY      ( 300 )

#define PONG_WORLD_LEFT_PADDEL_X  ( CSP_WORLD_MIN_X + CSP_PX_TO_WORLD(2) )
#define PONG_WORLD_LEFT_PADDEL_Y  ( 0 )

#define PONG_WORLD_RIGHT_PADDEL_X ( CSP_WORLD_MAX_X - CSP_PX_TO_WORLD(2) - PONG_WORLD_PADDEL_W )
#define PONG_WORLD_RIGHT_PADDEL_Y ( 0 )

#define PONG_WORLD_BALL_W       ( CSP_PX_TO_WORLD(1) )
#define PONG_WORLD_BALL_H       ( CSP_PX_TO_WORLD(4) )
#define PONG_WORLD_BALL_X       ( 0 )
#define PONG_WORLD_BALL_Y       ( 0 )
#define PONG_WORLD_BALL_VX      ( -100 )
#define PONG_WORLD_BALL_VY      (  48 )
#define PONG_WORLD_BALL_MAX_VX  ( 400 )
#define PONG_WORLD_BALL_MIN_VX  ( -400 )
#define PONG_WORLD_BALL_MAX_VY  ( 400 )
#define PONG_WORLD_BALL_MIN_VY  ( -400 )

#define PONG_WORLD_BALL_IVX     ( 5 )

#define PONG_POINTS_TO_WIN      ( 3 )
