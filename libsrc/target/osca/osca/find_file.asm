;  int find_file (char *filename, struct flos_file file);
;  CALLER linkage for function pointers
;
;	$Id: find_file.asm,v 1.4 2016-06-22 22:13:09 dom Exp $
;

SECTION code_clib
PUBLIC find_file
PUBLIC _find_file

EXTERN asm_find_file

find_file:
_find_file:
	pop		bc
	pop		de	; ptr to file struct
	pop		hl	; ptr to file name
	push	hl
	push	de
	push	bc

   jp asm_find_file
