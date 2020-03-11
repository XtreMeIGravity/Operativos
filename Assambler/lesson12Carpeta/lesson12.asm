; Calculator (Addition)
; Compile with: nasm -f elf lesson12.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson12.o -o lesson12
; Run with: ./lesson12
 
%include        'lesson11Func.asm'
 
SECTION .text
global  _start
 
_start:
 
    mov     eax, 90     ; move our first number into eax
    mov     ebx, 9      ; move our second number into ebx
    add     eax, ebx    ; add ebx to eax
    call    iprintLF    ; call our integer print with linefeed function
 
    call    quit