; Hello World Program (Calculating string length)
; Compile with: nasm -f elf lesson3.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson3.o -o lesson3
; Run with: ./lesson3
 
SECTION .data
msg     db      'Hello, brave new world!', 0Ah ; we can modify this now without having to update anywhere else in the program
 
SECTION .text
global  _start
 
_start:
 
    mov     ebx, msg        ; move the address of our message string into EBX
    mov     eax, ebx        ; move the address in EBX into EAX as well (Both now point to the same segment in memory)
 
nextchar:
    cmp     byte [eax], 0   ; compara y toma el primer byte del apuntador y lo compara con el valor (cadena) 0 que esta hasta el final
    jz      finished        ; si es zero salta a finished
    inc     eax             ; incrementa el apuntoador eax
    jmp     nextchar        ; salta a la etiqueta nextchar
 
finished:
    sub     eax, ebx        ; una sustracion  siempre se almacena eax  , en esta caso resta el ultimo valor en memoria ylo pasa al primero
 
    mov     edx, eax        ; edx respalda el valor eax
    mov     ecx, msg        ; mas de lo mismo    
    mov     ebx, 1
    mov     eax, 4
    int     80h
 
    mov     ebx, 0
    mov     eax, 1
    int     80h