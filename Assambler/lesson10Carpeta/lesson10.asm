; Hello World Program (Count to 10)
; Compile with: nasm -f elf lesson10.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson10.o -o lesson10
; Run with: ./lesson10
 
%include        'lesson7Func.asm'
 
SECTION .text
global  _start
 
_start:
 
    mov     ecx, 0          ; inicializa ecx en 0
 
nextNumber:
    inc     ecx             ; aumenta en 1 exc
 
    mov     eax, ecx        ; mueve la direccion exc a eax
    add     eax, 48         ; suma 48 a eax    , valor de eax=49
    push    eax             ; manda el valor de eax al stack
    mov     eax, esp        ; obtiene la direccion de eax del stack
    call    sprintLF        ; llama a la funcion sprintLF con un salto de linea
 
    pop     eax             ; saca el ultimo valor almacenado en eax
    cmp     ecx, 10         ; compara el valor de exc con 10
    jne     nextNumber      ; mientras no sea igual salta a la etiqueta nextNumber
 
    call    quit