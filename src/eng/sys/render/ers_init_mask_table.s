.module ers_pp
.optsdcc -mz80
.area _CODE

.include /ers_pp.s/

_ers_init_mask_table::
ers_init_mask_table_asm::
    ld hl,#_ERS_MASK_TABLE			;; base address of the mask table
    ld b,#0							;; counter
    ld c,#0							;; initial pixel value

    _ers_imt_mmt1:
    ld d,#0							;; initialise initial mask

    ld a,c
    and #0x88
    jr z,_ers_imt_mmt2
    ld a,d
    or #0x88
    ld d,a

    _ers_imt_mmt2:
    ld a,c
    and #0x44
    jr z,_ers_imt_mmt3
    ld a,d
    or #0x44
    ld d,a

    _ers_imt_mmt3:
    ld a,c
    and #0x22
    jr z,_ers_imt_mmt4
    ld a,d
    or #0x22
    ld d,a

    _ers_imt_mmt4:
    ld a,c
    and #0x11
    jr z,_ers_imt_mmt5

    ld a,d
    or #0x11
    ld d,a

    _ers_imt_mmt5:
    ld a,d
    cpl
    ld (hl),a						;; store final mask in table
    inc hl							;; increment position in table
    inc c							;; increment pixel value
    djnz _ers_imt_mmt1				;; loop
ret