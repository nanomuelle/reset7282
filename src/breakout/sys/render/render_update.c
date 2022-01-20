#include <sys/render/render.h>
#include <breakout/breakout.h>
#include <breakout/sys/render/render.h>

void breakout_sys_render_update(void) {
    csr_update();
}