; Time
; Compile with: nasm -f elf lesson21.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson21.o -o lesson21
; Run with: ./lesson21
 
%include        'lesson16Func.asm'
 
SECTION .data
msg        db      'Seconds since Jan 01 1970: ', 0h     ; Segundos desde Enero de 1970
 
SECTION .text
global  _start
 
_start:
 
    mov     eax, msg        ; apunta el registro eax al msg
    call    sprint          ; llama a la funcion sprint
 
    mov     eax, 13         ; llama a SYS_TIME (kernel opcode 13) Este nos devuelve los
                            ; segundos desde 1 Enero de 1970 en el registro eax
    int     80h             ; crea una interrupcion en el microprocesador para llamar a la opcion anterior


    call    iprintLF        ; Imprime el valor entero con un salto de linea
    call    quit            ; Finaliza el programa
