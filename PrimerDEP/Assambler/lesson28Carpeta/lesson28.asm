; Unlink
; Compile with: nasm -f elf lesson28.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson28.o -o lesson28
; Run with: ./lesson28
 
%include    'lesson16Func.asm'
 
SECTION .data
filename db 'readme.txt', 0h    ; nombre del archivo para borrar
 
SECTION .text
global  _start
 
_start:
 
    mov     ebx, filename       ; nombre del archivo  a borrar
    mov     eax, 10             ; llama SYS_UNLINK (kernel opcode 10) elimina el directorio
    int     80h                 ; crea una interrupcion en el microprocesador
 
    call    quit                ; termina el programa