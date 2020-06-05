; Calculator (Addition)
; Compile with: nasm -f elf lesson12.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson12.o -o lesson12
; Run with: ./lesson12
 
%include        'lesson11Func.asm'
 
SECTION .text
global  _start
 
_start:
 
    mov     eax, 90     ; almacena un 90 en eax
    mov     ebx, 9      ; almacena un 9 en ebx
    add     eax, ebx    ; suma eax + ebx y almacena el resultado en eax
    call    iprintLF    ; Imprime un entero con un salto de linea
 
    call    quit