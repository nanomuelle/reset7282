.module ers_pp
.optsdcc -mz80
.area _CODE

.include /ers_pp.s/

;;
;; DRAW SPRITE PIXEL PERFECT
;;
;; HL = screen address
;; DE = pointer to array of sprite data
;; A = pixel offset in sprite
;; B = height
;; C = width

_ers_pp_draw_sprite::
    ;; GET Parameters from the stack 
    ;; pop  af   ;; [3] AF = Return Address
    pop  iy   ;; iy = Return Address

    ;; u8* pmem, u8 *sprite, u8 w, u8 h, u16 shift
    pop  hl ;; [3] HL = Destination address (Video memory location)
    pop  de ;; [3] DE = Source Address (Sprite data array)
    pop  bc ;; [3] BC = h shift/l shift
    ld   a,c ;; a = shift
    pop  bc ;; BC = Height/Width (B = Height, C = Width)

    push iy   ;; [4] Put returning address in the stack again
                ;;      as this function uses __z88dk_callee convention
    push ix ;; guardamos ix para recuperarlo justo antes del ret (cosas del c)

    ;; start of algoritm
ers_pp_draw_sprite_asm::
;    or a
;    jr z,_ers_pp_ds_sprite_draw2
;    inc c					        ;; when sprite is shifted, the width is one byte larger

    _ers_pp_ds_sprite_draw2:
        ex de,hl
        add a,a				        ;; A = A * 2
        add a,l				        ;; add low byte of array 
        ld l,a
        ld a,h	
        adc a,#0
        ld h,a
                                    ;; HL = address in array
        ld a,(hl)
        inc hl
        ld h,(hl)
        ld l,a				        ;; read address from array = address of sprite pixel data
        ex de,hl

        push bc
        pop ix						;; low byte of IX = C
        							;; high byte of IX = B

        ;; B = upper 8-bits (bits 15..8) of mask table memory address
        ld b,#_ERS_MASK_TABLE/256

    _ers_pp_ds_height:
        push ix
        push hl

    _ers_pp_ds_width:
        ld a,(de)					;; get byte of sprite pixel data
        ld c,a						;; C = byte of sprite pixel data/look-up table value
                                    ;; BC = address (in look-up table) of mask corresponding to this sprite pixel data
        ld a,(bc)					;; lookup mask from table
        and (hl)					;; mask pixels on screen (remove pixels which will be replaced)
        or c						;; combine with sprite pixel data
        ld (hl),a					;; write result to screen 
        inc de
        inc hl
        .db #0xdd					;; DEC LIX
        dec l
        jr nz,#_ers_pp_ds_width
        pop hl
        call #_SCR_NEXT_LINE
        pop ix
        .db #0xdd					;; DEC HIX
        dec h
        jr nz,#_ers_pp_ds_height

    pop ix
    ret