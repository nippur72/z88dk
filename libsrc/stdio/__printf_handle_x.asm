    MODULE  __printf_handle_x
    SECTION code_clib
    PUBLIC  __printf_handle_x
    PUBLIC  __printf_handle_p
    EXTERN  __printf_number

    EXTERN  __printf_set_base
    EXTERN  __printf_disable_plus_flag
    EXTERN  __printf_set_upper

__printf_handle_x:
__printf_handle_p:
IF __CPU_INTEL__ | __CPU_GBZ80__
    ld      c,16
    call    __printf_set_base
    call    __printf_disable_plus_flag
ELSE
    ld      (ix-9),16
    res     1,(ix-4)        ;disable '+' flag
ENDIF
    ld      c,0		;unsigned
    jp      __printf_number
