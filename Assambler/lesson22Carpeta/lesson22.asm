; Create
; Compile with: nasm -f elf lesson22.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson22.o -o lesson22
; Run with: ./lesson22
 
%include    'lesson16Func.asm'
 
SECTION .data
filename db 'readme.txt',       ; el nombre del archivo a crear
 
SECTION .text
global  _start
 
_start:
 
    mov     ecx, 0777           ; Establece los permisos de lectura , escrituras y  ejecucion 
    mov     ebx, filename       ; filename we will create
    mov     eax, 8              ; llama a sys_creat
    int     80h                 ; crea una interrupcion para que se ejecute el comando anterior

    call    quit                ; llama a la funcion de terminar el programa