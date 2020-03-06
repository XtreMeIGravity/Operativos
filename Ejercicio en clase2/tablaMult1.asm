%include        'functions.asm'

 
SECTION .data
msg1    db      'x', 0, 0h          ; NOTE the null terminating byte
msg2    db      '=', 0, 0h  ; NOTE the null terminating byte
 
SECTION .text
global  _start
 
_start:

    mov     ecx, 0
    mov     ebx, 1

nextNumber:  ;ETIQUETA PARA CICLO
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

    mov     ecx , 0        ;REsetea el valor de el aumento 
    inc     ebx            ;INcrementa la multiplicacion en 1
    cmp     ebx, 10        ;Si la segunda variable es igual 10 termina si no regresa a la etiqueta
    jne     nextNumber     ;Regreso etiqueta
 
    call    quit            ;FINALIZA :D