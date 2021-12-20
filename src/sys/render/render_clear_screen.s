.module reset_sys_render

_sys_render_clearScreen::
sys_render_clearScreen_asm::
    call 0xbc14 ;; firmware SCR CLEAR
    ret