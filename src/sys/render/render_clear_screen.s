.module reset_sys_render

_sys_render_clearScreen::
    call 0xbc14 ;; firmware SCR CLEAR
    ret