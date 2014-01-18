
XLIB __stdio_scanf_x
XDEF __stdio_scanf_p

LIB __stdio_scanf_sm_hex, __stdio_scanf_number_head
LIB l_inc_sp, asm_strtou, __stdio_scanf_number_tail_int

__stdio_scanf_x:
__stdio_scanf_p:

   ; %x, %p converter called from vfscanf()
   ;
   ; enter : ix = FILE *
   ;         de = void *buffer
   ;         bc = field width (0 means default)
   ;         hl = int *p
   ;
   ; exit  : carry set if error
   ;
   ; uses  : all except ix

   ; EAT WHITESPACE AND READ NUMBER INTO BUFFER

   push hl                     ; save int *p
   push de                     ; save void *buffer
   
   ld a,9                      ; nine hex digits + prefix needed to reach overflow
   ld hl,__stdio_scanf_sm_hex  ; hex number state machine

   call __stdio_scanf_number_head
   jp c, l_inc_sp - 4          ; if stream error, pop twice and exit

   ; ASC-II HEX TO 16-BIT INTEGER
   
   pop hl                      ; hl = void *buffer
   ld bc,16                    ; base 16 conversion
   ld e,b
   ld d,b                      ; de = 0 = char **endp
   
   call asm_strtou
   pop de                      ; de = int *p
   
   ; WRITE RESULT TO INT *P
   
   ; check for conversion errors
   
   jp nc, __stdio_scanf_number_tail_int
   jp p, __stdio_scanf_number_tail_int
   
   ; invalid number string
   ; carry set
   
   ret
