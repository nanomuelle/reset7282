.module reset_sys_input

_sys_input_waitKey::
sys_input_waitKey_asm::
    call 0xbb06
    ld   l, a       ; returns output in l to c language calls
    ret