#ifndef PONG
#define PONG

#include <globals.h>

// WORLD
#define PONG_PX_TO_WORLD(px)    ( 256 * px ) // PX TO PHYSICS UNITS

#define PONG_WORLD_W            ( PONG_PX_TO_WORLD( ROOM_TXT_BOX_W ) )
#define PONG_WORLD_H            ( PONG_PX_TO_WORLD( ROOM_TXT_BOX_H ) )

#define PONG_WORLD_MIN_X        ( (-PONG_WORLD_W / 2) + PONG_PX_TO_WORLD(1) )
#define PONG_WORLD_MAX_X        ( ( PONG_WORLD_W / 2) - PONG_PX_TO_WORLD(1) )
#define PONG_WORLD_MIN_Y        ( (-PONG_WORLD_H / 2) + PONG_PX_TO_WORLD(2) )
#define PONG_WORLD_MAX_Y        ( ( PONG_WORLD_H / 2) - PONG_PX_TO_WORLD(2) )

// ENTITIES
typedef enum PongEntityIdEnum {
    PONG_ENTITY_ID_BALL,
    PONG_ENTITY_ID_LEFT_PADDEL,
    PONG_ENTITY_ID_RIGHT_PADDEL
} TPongEntityId;

#define PONG_WORLD_PADDEL_W     ( PONG_PX_TO_WORLD(1) )
#define PONG_WORLD_PADDEL_H     ( PONG_PX_TO_WORLD(16) )

#define PONG_WORLD_PADDEL_VX      ( 0 )
#define PONG_WORLD_PADDEL_VY      ( 250 )

#define PONG_WORLD_LEFT_PADDEL_X  ( PONG_WORLD_MIN_X + PONG_PX_TO_WORLD(2) )
#define PONG_WORLD_LEFT_PADDEL_Y  ( 0 )

#define PONG_WORLD_RIGHT_PADDEL_X ( PONG_WORLD_MAX_X - PONG_PX_TO_WORLD(2) )
#define PONG_WORLD_RIGHT_PADDEL_Y ( 0 )

#define PONG_WORLD_BALL_W       ( PONG_PX_TO_WORLD(1) )
#define PONG_WORLD_BALL_H       ( PONG_PX_TO_WORLD(4) )
#define PONG_WORLD_BALL_X       ( 0 )
#define PONG_WORLD_BALL_Y       ( 0 )
#define PONG_WORLD_BALL_VX      ( 125 )
#define PONG_WORLD_BALL_VY      ( 100 )

#endif