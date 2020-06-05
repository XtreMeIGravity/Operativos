; Calculator (Subtraction)
; Compile with: nasm -f elf lesson13.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson13.o -o lesson13
; Run with: ./lesson13
 
%include        'lesson11Func.asm'
 
SECTION .text
global  _start
 
_start:
 
    mov     eax, 90     ; almacena un 90 en eax
    mov     ebx, 9      ; almacena un 9 en ebx
    sub     eax, ebx    ; resta 90 - 9 y almacena el resultado en eax
    call    iprintLF    ; Imprime un entero con un salto de linea
 
    call    quit