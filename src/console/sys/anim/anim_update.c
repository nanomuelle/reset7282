#include "anim.h"

void m_csa_updateOne(TEntity* entity) {
    if (entity->components & CME_ENTITY_COMPONENT_ANIM) {
        u8   frameIndex = entity->anim_frame_index;
        u8** frames = entity->anim_frames;
        entity->sprite = frames[frameIndex];

        ++frameIndex;
        if (frameIndex == entity->anim_num_frames) {
            frameIndex = 0;
        }
        entity->anim_frame_index = frameIndex;
    }
}

void csa_update() {
    cme_forAll(m_csa_updateOne);
}