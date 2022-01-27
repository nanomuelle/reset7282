.module ers_pp
.optsdcc -mz80
.area _CODE

.include /ers_pp.s/

;; restore a rectangle to the screen
_ers_restore_one_bg_exp::
    ;; GET Parameters from the stack
    pop  iy   ;; iy = Return Address

    ;; u8* pmem, u8 *sprite, u8 w, u8 h, u16 shift
    pop  hl ;; HL = screen address of sprite
    pop  de ;; DE = address to store screen data
    pop  bc ;; BC = Height/Width (B = Height, C = Width)
    pop  af ;; A = pixel offset into byte

    push iy   ;; Put returning address in the stack again

    ;; como modificaremos ix, lo guardamos para restaurarlo
    ;; push ix ;; guardamos ix para recuperarlo justo antes del ret (cosas del c)

;; HL = screen address of sprite
;; H = x byte coord
;; L = y line
;; DE = address to store screen data
;; B = height
;; C = width (unshifted in bytes)
;; A = pixel offset into byte
ers_restore_one_bg_exp_asm::
    or a
    jr nz,ers_robg_shifted
;    dec c					;; when sprite is shifted, the width is one byte smaller

    ;; todo: select the correct masks depending on shift
    ;; candidate to self modified code
    ers_robg_unshifted_height:
        push bc
        push hl

        ld b,#0
        dec c
        ldir

        pop hl
        call #_SCR_NEXT_LINE ; TODO calcular inline to avoid call and optimize for speed

        pop bc
        djnz ers_robg_unshifted_height
        jr ers_robg_end

    ;;
    ;;      0b01110111,    0b10001000
    ;;  and 0b00110011, or 0b01000100
    ;;  -----------------------------
    ;;      0b00110011,    0b11001100
    ;;  and 0b00010001, or 0b11101110
    ;;  -----------------------------
    ;;      0b00010001,    0b11101110
    ers_robg_shifted:
        push hl
        ld hl,#(ers_robg_shifted_width_first_byte_mask + 1)

    ers_robg_shifted_1:
        dec a
        jr nz,#ers_robg_shifted_2
        ld (hl),#0b01110111
        ld hl,#(ers_robg_shifted_width_last_byte_mask + 1)
        ld (hl),#0b10001000
        jr ers_robg_shifted_loop

    ers_robg_shifted_2:
        dec a
        jr nz,#ers_robg_shifted_3
        ld (hl),#0b00110011
        ld hl,#(ers_robg_shifted_width_last_byte_mask + 1)
        ld (hl),#0b11001100
        jr ers_robg_shifted_loop

    ers_robg_shifted_3:
        ld (hl),#0b00010001
        ld hl,#(ers_robg_shifted_width_last_byte_mask + 1)
        ld (hl),#0b11101110

    ers_robg_shifted_loop:
        pop hl
    ers_robg_shifted_height:
        push bc
        push hl

        ers_robg_shifted_width_first_byte:
            ;; first byte
            ld a,(de)					;; read from buffer
            ers_robg_shifted_width_first_byte_mask:
            or #0b00000000              ;; and mask (automodified code)
            ld (hl),a					;; write to screen

            dec c                       ;; descontamos 1 byte

            ers_robg_shifted_width_middle_next_byte:
                inc hl                      ;; apuntamos a la siguiente posicion de memoria
                inc de                      ;; apuntamos al siguiente byte del sprite
                dec c
                jr nz,ers_robg_shifted_width_middle;

            ;; last byte
            inc hl
            inc de
            ld a,(de)					;; read from buffer
            ers_robg_shifted_width_last_byte_mask:
            or #0b00000000              ;; and mask (automodified code)
            ld (hl),a					;; write to screen

            ;; restore counters and repeat for each line
            pop hl
            call #_SCR_NEXT_LINE
            pop bc
            djnz #ers_robg_shifted_height
        
        ers_robg_end:
            ret

        ers_robg_shifted_width_middle:
            ld a,(de)
            ld (hl), a
            jr ers_robg_shifted_width_middle_next_byte

;; 1 byte        = 4 pixels (mode 1)
;; width         = w     bytes
;; width shifted = w + 1 bytes
;; height        = h
;;
;; example w = 2, h = 3
;; sprite
;;
;; spr_0 (unshifted)
;; [dddd  1][dddd  1][.... 2]
;; [dddd  3][dddd  4][.... 3]
;; [dddd  6][dddd  7][.... 4]
;;                          01230123    01230123 mode 1 pixel map
;; spr_1 (shift 1) masks: 0b01110111, 0b10001000
;; [_ddd  9][dddd 10][d___ 11]
;; [_ddd 12][dddd 13][d___ 14]
;; [_ddd 15][dddd 16][d___ 17]
;;                          01230123    01230123 mode 1 pixel map
;; spr_2 (shift 2) masks: 0b00110011, 0b11001100
;; [__dd  9][dddd 10][dd__ 11]
;; [__dd 12][dddd 13][dd__ 14]
;; [__dd 15][dddd 16][dd__ 17]
;;                          01230123    01230123 mode 1 pixel map
;; spr_3 (shift 3) masks: 0b00010001, 0b11101110
;; [___d  9][dddd 10][ddd_ 11]
;; [___d 12][dddd 13][ddd_ 14]
;; [___d 15][dddd 16][ddd_ 17]
;;

