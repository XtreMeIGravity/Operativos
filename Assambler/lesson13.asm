; Calculator (Subtraction)
; Compile with: nasm -f elf lesson13.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson13.o -o lesson13
; Run with: ./lesson13
 
%include        'lesson11Func.asm'
 
SECTION .text
global  _start
 
_start:
 
    mov     eax, 90     ; move our first number into eax
    mov     ebx, 9      ; move our second number into ebx
    sub     eax, ebx    ; subtract ebx from eax
    call    iprintLF    ; call our integer print with linefeed function
 
    call    quit