%include        'functions.asm'

 
SECTION .data
msg1    db      'x', 0, 0h          ; NOTE the null terminating byte
msg2    db      '=', 0, 0h  ; NOTE the null terminating byte
 
SECTION .text
global  _start
 
_start:

    mov     ecx, 0
    mov     ebx, 1
 
nextNumber:
    inc     ecx;INcrementa

    mov     eax, ebx
    call    iprint        ; Imprime el 1

    mov     eax, msg1     ;IMprime el x
    call    sprint

    mov     eax, ecx
    call    iprint        ; IMprime el aumento

    mov     eax, msg2     ;IMprime el =
    call    sprint

    mov     eax, ecx     
    mov     ebx, ebx    
    mul     ebx
    call    iprintLF      ;Imprime  el resultado

    cmp     ecx, 10
    jne     nextNumber

    mov     ecx , 0
    inc     ebx;INcrementa
    cmp     ebx, 10
    jne     nextNumber
 
    call    quit