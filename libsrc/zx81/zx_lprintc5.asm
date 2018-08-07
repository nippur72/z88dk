;
;		Print on the ZX PRINTER with a small ZX81 font in 51 columns 
;
;		Stefano Bodrato, 2018
;
;
;	$Id: zx_lprintc5.asm $
;

		SECTION code_clib
		PUBLIC    zx_lprintc5
		PUBLIC    _zx_lprintc5
		
		EXTERN  zx_print_buf
		EXTERN  asctozx81
		EXTERN  prbuf_x		; set this one to 0 to wipe the buffer


.offsets_table
         defb	128,64,32,16,8,4,2,1
	
.zx_lprintc5
._zx_lprintc5

	ld	a,(prbuf_x)
	and a
	call z,buf_reset
	ld	hl,2
	add	hl,sp
	ld	(charptr+1),hl
	ld	a,(hl)


.charptr
	ld	 hl,0
	ld	a,(hl)
IF STANDARDESCAPECHARS
	cp  10		; CR?
	jp  z,newline
ELSE
	cp  13		; CR?
	jp  z,newline
ENDIF
	call asctozx81	; now A holds the character code

	ld e,a
	rla
	ld	a,0		; NOP
	jr	nc,nocpl
	ld a,$2f	; CPL
.nocpl
	ld	(invrs),a
	ld	(invrs2),a
	ld	a,e
	
	and	127		; mask the inverse bit
	jr	z,space	; space chr
	
	ld	c,a
		
	ld ix,font5-7
	ld	de,7
.fontptr
	add ix,de
	dec a
	jr	nz,fontptr

	ld	a,c			; font is slightly condensed, here we rebuild the first row
	sub 9
	sbc a,a
	jr	nz,empty_row
	ld a,$AF		; xor a, overrides "ld a,(ix+1)" used on characters 0..8
.empty_row
	ld (firstbyte),a
	
	ld	a,(prbuf_x)
	ld	c,a
	AND     7	; @00000111
	ld       hl,offsets_table
	ld       e,a
	;ld       d,0
	add      hl,de
	ld       a,(hl)
	ld       (_smc1+1),a
	ld	a,c
	
	rra
	srl a
	srl a
	;ld	d,0
	ld	e,a
	ld hl,buf
	add hl,de

	ld	(rowadr1)+1,hl

	ld       d,8
	xor a				;First chr shape line

	ld       a,(ix+1)    ; First chr shape line (=third one for chr$ codes <=8)
.firstbyte
	xor a	; ld a,0  ..first chr shape line for the other characters, SMC disables it when necessary
		 
.invrs
		nop	; toggles between "nop" and "cpl"
		ld	c,a
	
._oloop		

         ld       b,5               ;Load width
._smc1   ld       a,1               ;Load pixel mask
._iloop  sla      c                 ;Test leftmost pixel
         jr       nc,_noplot        ;See if a plot is needed
         ld       e,a
         or (hl)
         ld (hl),a
         ld       a,e
._noplot rrca
         jr       nc,_notedge       ;Test if edge of byte reached
         inc      hl                ;Go to next byte
._notedge djnz     _iloop

	; ---------
.rowadr1
	ld	hl,0	; current address
	push de
	ld	de,32
	add hl,de
	pop de
	ld	(rowadr1+1),hl
	; ---------

         ld       a,(ix+0)          ;Load one line of image
.invrs2
	nop	; changed into nop / cpl
	ld	c,a
	
         inc      ix
         dec d
         jr	nz,_oloop

.space
	ld	a,(prbuf_x)
	cp 250	; last valid column position ?
	jr z,newline
	add 5
	ld	(prbuf_x),a
	ret
	
.newline
	ld	hl,buf
	call zx_print_buf
.buf_reset
	ld	hl,buf
	xor  a
	ld	(prbuf_x),a
	ld	(hl),a
	ld	d,h
	ld	e,l
	inc de
	ld	bc,255
	ldir
	ret



		
	SECTION rodata_clib


.font5

; 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,		; 0
defb 0xE0 , 0xE0 , 0xE0 , 0x00 , 0x00 , 0x00 , 0x00
defb 0x38 , 0x38 , 0x38 , 0x00 , 0x00 , 0x00 , 0x00
defb 0xF8 , 0xF8 , 0xF8 , 0x00 , 0x00 , 0x00 , 0x00
defb 0x00 , 0x00 , 0x00 , 0xE0 , 0xE0 , 0xE0 , 0xE0
defb 0xE0 , 0xE0 , 0xE0 , 0xE0 , 0xE0 , 0xE0 , 0xE0
defb 0x38 , 0x38 , 0x38 , 0xE0 , 0xE0 , 0xE0 , 0xE0
defb 0xF8 , 0xF8 , 0xF8 , 0xE0 , 0xE0 , 0xE0 , 0xE0
defb 0x50 , 0xA8 , 0x50 , 0xA8 , 0x50 , 0xA8 , 0x50
defb 0x00 , 0x00 , 0x00 , 0xA8 , 0x50 , 0xA8 , 0x50
defb 0x50 , 0xA8 , 0x50 , 0x00 , 0x00 , 0x00 , 0x00		; 10
defb 0x50 , 0x50 , 0x50 , 0x00 , 0x00 , 0x00 , 0x00
defb 0x60 , 0x90 , 0xC0 , 0x80 , 0x80 , 0xF0 , 0x00
defb 0x20 , 0x70 , 0x40 , 0x70 , 0x10 , 0x70 , 0x20
defb 0x00 , 0x20 , 0x00 , 0x00 , 0x00 , 0x20 , 0x00
defb 0x20 , 0x50 , 0x10 , 0x20 , 0x00 , 0x20 , 0x00
defb 0x10 , 0x20 , 0x20 , 0x20 , 0x20 , 0x10 , 0x00
defb 0x40 , 0x20 , 0x20 , 0x20 , 0x20 , 0x40 , 0x00
defb 0x00 , 0x40 , 0x20 , 0x10 , 0x20 , 0x40 , 0x00
defb 0x00 , 0x10 , 0x20 , 0x40 , 0x20 , 0x10 , 0x00
defb 0x00 , 0x00 , 0x70 , 0x00 , 0x70 , 0x00 , 0x00		; 20
defb 0x00 , 0x00 , 0x20 , 0x70 , 0x20 , 0x00 , 0x00
defb 0x00 , 0x00 , 0x00 , 0x70 , 0x00 , 0x00 , 0x00
defb 0x00 , 0x00 , 0x50 , 0x20 , 0x50 , 0x00 , 0x00
defb 0x10 , 0x10 , 0x20 , 0x20 , 0x40 , 0x40 , 0x00
defb 0x00 , 0x20 , 0x00 , 0x00 , 0x00 , 0x20 , 0x40
defb 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x20 , 0x40
defb 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x20 , 0x00
defb 0x60 , 0x90 , 0x90 , 0x90 , 0x90 , 0x60 , 0x00
defb 0x20 , 0x60 , 0x20 , 0x20 , 0x20 , 0x70 , 0x00
defb 0x60 , 0x90 , 0x10 , 0x60 , 0x80 , 0xF0 , 0x00		; 30
defb 0xE0 , 0x10 , 0x60 , 0x10 , 0x10 , 0xE0 , 0x00
defb 0x20 , 0x60 , 0xA0 , 0xA0 , 0xF0 , 0x20 , 0x00
defb 0xF0 , 0x80 , 0x60 , 0x10 , 0x90 , 0x60 , 0x00
defb 0x70 , 0x80 , 0xE0 , 0x90 , 0x90 , 0x60 , 0x00
defb 0xF0 , 0x10 , 0x20 , 0x20 , 0x40 , 0x40 , 0x00
defb 0x60 , 0x90 , 0x60 , 0x90 , 0x90 , 0x60 , 0x00
defb 0x60 , 0x90 , 0x90 , 0x70 , 0x10 , 0xE0 , 0x00
defb 0x60 , 0x90 , 0x90 , 0xF0 , 0x90 , 0x90 , 0x00
defb 0xE0 , 0x90 , 0xE0 , 0x90 , 0x90 , 0xE0 , 0x00
defb 0x60 , 0x90 , 0x80 , 0x80 , 0x90 , 0x60 , 0x00		; 40
defb 0xC0 , 0xA0 , 0x90 , 0x90 , 0x90 , 0xE0 , 0x00
defb 0xF0 , 0x80 , 0xE0 , 0x80 , 0x80 , 0xF0 , 0x00
defb 0xF0 , 0x80 , 0xE0 , 0x80 , 0x80 , 0x80 , 0x00
defb 0x60 , 0x80 , 0x80 , 0xB0 , 0x90 , 0x60 , 0x00
defb 0x90 , 0x90 , 0xF0 , 0x90 , 0x90 , 0x90 , 0x00
defb 0x70 , 0x20 , 0x20 , 0x20 , 0x20 , 0x70 , 0x00
defb 0x30 , 0x10 , 0x10 , 0x10 , 0x90 , 0x60 , 0x00
defb 0x90 , 0xA0 , 0xC0 , 0xA0 , 0x90 , 0x90 , 0x00
defb 0x80 , 0x80 , 0x80 , 0x80 , 0x80 , 0xF0 , 0x00
defb 0x88 , 0xD8 , 0xA8 , 0x88 , 0x88 , 0x88 , 0x00		; 50
defb 0x90 , 0xD0 , 0xB0 , 0x90 , 0x90 , 0x90 , 0x00
defb 0x60 , 0x90 , 0x90 , 0x90 , 0x90 , 0x60 , 0x00
defb 0xE0 , 0x90 , 0x90 , 0xE0 , 0x80 , 0x80 , 0x00
defb 0x60 , 0x90 , 0x90 , 0x90 , 0xB0 , 0x70 , 0x00
defb 0xE0 , 0x90 , 0x90 , 0xE0 , 0x90 , 0x90 , 0x00
defb 0x60 , 0x80 , 0x60 , 0x10 , 0x10 , 0xE0 , 0x00
defb 0xF8 , 0x20 , 0x20 , 0x20 , 0x20 , 0x20 , 0x00
defb 0x90 , 0x90 , 0x90 , 0x90 , 0x90 , 0x60 , 0x00
defb 0x90 , 0x90 , 0x90 , 0xA0 , 0xA0 , 0x40 , 0x00
defb 0x88 , 0x88 , 0x88 , 0x88 , 0xA8 , 0x50 , 0x00		; 60
defb 0x88 , 0x50 , 0x20 , 0x20 , 0x50 , 0x88 , 0x00
defb 0x90 , 0x90 , 0x50 , 0x20 , 0x40 , 0x80 , 0x00
defb 0xF0 , 0x10 , 0x20 , 0x40 , 0x80 , 0xF0 , 0x00



SECTION data_clib

.prbuf_x	defb 0

SECTION bss_clib

.buf
	defs 256

