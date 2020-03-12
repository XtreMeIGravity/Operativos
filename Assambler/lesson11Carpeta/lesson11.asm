; Hello World Program (Count to 10 itoa)
; Compile with: nasm -f elf lesson11.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson11.o -o lesson11
; Run with: ./lesson11
 
%include        'lesson11Func.asm'
 
SECTION .text
global  _start
 
_start:
 
    mov     ecx, 0          ;coloca el valor de ecx en 0
 
nextNumber:
    inc     ecx             ;incrementa en 1 el valor de ecx
    mov     eax, ecx        ;duplica el valor de eax en ecx para la impresion 
    call    iprintLF        ;Imprime el entero con un salto de linea
    cmp     ecx, 10         ;Compara ecx con 10
    jne     nextNumber      ;se repite hasta que ecx sea igual a 10 
 
    call    quit