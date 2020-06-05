; Fork
; Compile with: nasm -f elf lesson20.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson20.o -o lesson20
; Run with: ./lesson20
 
%include        'lesson16Func.asm'
 
SECTION .data
childMsg        db      'This is the child process', 0h     ; a message string
parentMsg       db      'This is the parent process', 0h    ; a message string
 
SECTION .text
global  _start
 
_start:
 
    mov     eax, 2              ; manda a llamar SYS_FORK (Esta crea un child process o proceso hijo)
    int     80h                 ; Crea una interrupcion el microprocesador para ejecutar 
                                ; el comando anterior
 
    cmp     eax, 0              ; si el valor de eax es igual a 0 
    jz      child               ; salta a la etiqueta child
 
parent:
    mov     eax, parentMsg      ; Apunta el registro eax a la variable parentMsg
    call    sprintLF            ; Imprime el mensaje con un salto de linea
 
    call    quit                ; termina el proceso Padre
 
child:
    mov     eax, childMsg       ; Apunta el registro eax a la variable childMsg
    call    sprintLF            ; Imprime el mensaje con un salto de linea
 
    call    quit                ;  termina el proceso Hijo