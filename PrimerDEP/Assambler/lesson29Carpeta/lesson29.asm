; Socket
; Compile with: nasm -f elf lesson29.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson29.o -o lesson29
; Run with: ./lesson29
 
%include    'lesson16Func.asm'
 
SECTION .text
global  _start
 
_start:
 
    xor     eax, eax            ; Limpia el registro
    xor     ebx, ebx            ; Limpia el registro
    xor     edi, edi            ; Limpia el registro
    xor     esi, esi            ; Limpia el registro
 
_socket:
 
    push    byte 6              ; Almacena 6 en el stack (IPPROTO_TCP)
    push    byte 1              ; Almacena 1 en el stack (SOCK_STREAM)
    push    byte 2              ; Almacena 2 en el stack (PF_INET)
    mov     ecx, esp            ; mueve la direccion de los argumentos a ecx
    mov     ebx, 1              ; llama subroutine SOCKET (1)
    mov     eax, 102            ; llama SYS_SOCKETCALL (kernel opcode 102)
    int     80h                 ; crea una interrupcion para ejecutar el comando anterior
 
    call    iprintLF            ; Imprime el valor que retorna SYS_SOCKETCALL
 
_exit:
 
    call    quit                ; termina el programa