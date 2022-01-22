#pragma once

#include "man/entity/entity.h"

#include "sys/physics/physics.h"
#include "sys/render/render.h"
#include "sys/anim/anim.h"

#define M1_BYTES_TO_PX(bytes) ( ( bytes ) * 4 )   // bytes to px mode 1
#define M1_PX_TO_BYTES(px)    ( ( px ) / 4 )      // px to bytes mode 1
