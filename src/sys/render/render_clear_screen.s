.module reset_sys_render

_render_clearScreen::
_render_clearScreen_asm::
    call 0xbc14 ;; firmware SCR CLEAR
    ret