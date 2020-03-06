%include        'functions.asm'

SECTION .data
msg1    db      'x', 0h  ; NOTE the null terminating byte
msg2    db      '=', 0h  ; NOTE the null terminating byte
 
SECTION .text
global  _start
 
_start:

    mov     ecx, 0      ;var1
    mov     ebx, 0      ;var2

Ciclo1:  ;ETIQUETA PARA CICLO
    inc     ecx         ;Incrementa var1
    mov     ebx, 0
Ciclo2:
    inc     ebx         ;Incrementa var2

    mov     eax, ecx    ;Apunta el valor el ecx a eax
    call    iprint      ;ImprimeEntero el valor de nuestra var2 para esto requiere que el valor a imprimir este en eax

    mov     eax, msg1   ;Apunta el valor el msg1 a eax
    call    sprint      ;ImprimeString el x para esto requiere que el valor a imprimir este en eax

    mov     eax, ebx    ;Apunta el valor el ecx a eax
    call    iprint      ;ImprimeEntero el valor de nuestra var2 para esto requiere que el valor a imprimir este en eax

    mov     eax, msg2   ;Apunta el valor el msg2 a eax
    call    sprint      ;ImprimeString el x para esto requiere que el valor a imprimir este en eax

    mov     eax, ecx    ;asigna ecx a eax
    mov     ebx, ebx    ;asigna ebx a ebx  NO NECESARIO
    mul     ebx         ;Multiplica el eax  x ebx y el resultado se guarda en eax
    call    iprintLF    ;Imprime  el resultado

    cmp     ebx, 10     ;Si la segunda variable es igual 10 termina si no regresa a la etiqueta
    jne     Ciclo2      ;Regreso etiqueta

    cmp     ecx, 10     ;Si la segunda variable es igual 10 termina si no regresa a la etiqueta
    jne     Ciclo1      ;Regreso etiqueta
 
    call    quit            ;FINALIZA :D