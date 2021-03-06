.module reset_sys_render

_sys_render_init::
sys_render_init_asm::
    ld  a, #0        ;; PEN 0
    ld  bc, #0x0000  ;; BLACK
    call 0xBC32      ;; SRC SET INK

    ld  a, #1        ;; PEN 1
    ld  bc, #0x1A1A  ;; BRIGHT WHITE
    call 0xBC32      ;; SRC SET INK

    ld  a, #2        ;; PEN 2
    ld  bc, #0x0C0C  ;; RED
    call 0xBC32      ;; SRC SET INK

    ld  a, #3        ;; PEN 3
    ld  bc, #0x0A0A  ;; CYAN
    call 0xBC32      ;; SRC SET INK

    ld  bc, #0x0000  ;; BLACK
    call 0xBC38      ;; SRC SET BORDER

    ret