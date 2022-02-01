#pragma once

#include <eng/eng.h>

#define ECM_MAX_COLLISIONS 5

// TYPES
typedef struct ECM_collision_struct {
    TEEM_entity *e1;
    TEEM_entity *e2;
} TECM_collision;

typedef void (*TECM_callback)(TECM_collision *);

// PRIVATE
extern TECM_collision   m_ecm_buffer[ECM_MAX_COLLISIONS]; // collisions buffer
extern TECM_collision*  m_ecm_next_free;                  // ptr to the next free entity
extern u8               m_ecm_num;                        // num collisions stored

// PUBLIC
extern void             ecm_reset       (void);
extern TECM_collision*  ecm_create      (void);
extern void             ecm_forEach     (TECM_callback);
