.module ers_pp
.optsdcc -mz80
.area _CODE

.include /ers_pp.s/

;;
;; store a rectangle from the screen into a buffer
;;
;; HL = screen address of sprite
;; DE = address to store screen data
;; B = height
;; C = width (unshifted in bytes)
;; A = pixel offset into byte
_ers_capture_one_bg_exp::
    ;; GET Parameters from the stack 
    pop  iy   ;; iy = Return Address

    ;; u8* pmem, u8 *sprite, u8 w, u8 h, u16 shift
    pop  hl ;; HL = screen address of sprite
    pop  de ;; DE = address to store screen data
    pop  bc ;; BC = Height/Width (B = Height, C = Width)
    pop  af ;; A = pixel offset into byte

    push iy   ;; Put returning address in the stack again

ers_capture_one_bg_exp_asm::
    ; or a
    ; jr nz,ers_cobg_height
    ; dec c					;; when sprite is shifted, the width is one byte larger

    ers_cobg_height:
        push bc
        push hl
        ld b,#0
        ; sprite_back_width:
            ldir    ; [21/16]
                    ; Repeats LDI (LD (DE),(HL), 
                    ; then increments DE, HL, 
                    ; and decrements BC) 
                    ; until BC=0. Note that if BC=0 before this instruction is called, it will loop around until BC=0 again.

            ; ld a,(hl)		             [7]		;; read from screen
            ; ld (de),a		             [7]		;; store to buffer
            ; inc hl                     [6]
            ; inc de                     [6]
            ; dec c                      [4]
            ; jr nz,sprite_back_width [12/7]
            ;                        [35/30]

        pop hl
        call #_SCR_NEXT_LINE
        pop bc
        djnz ers_cobg_height
    ret