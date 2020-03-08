; Calculator (Multiplication)
; Compile with: nasm -f elf lesson14.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson14.o -o lesson14
; Run with: ./lesson14
 
%include        'lesson11Func.asm'
 
SECTION .text
global  _start
 
_start:
 
    mov     eax, 90     ; move our first number into eax
    mov     ebx, 9      ; move our second number into ebx
    mul     ebx         ; multiply eax by ebx
    call    iprintLF    ; call our integer print with linefeed function
 
    call    quit