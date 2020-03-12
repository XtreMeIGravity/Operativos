; Hello World Program (Passing arguments from the command line)
; Compile with: nasm -f elf lesson8.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson8.o -o lesson8
; Run with: ./lesson8
 
%include        'lesson7Func.asm'
 
SECTION .text
global  _start
 
_start:
 
    pop     ecx             ; manda el numero de argumentos a la pila
 
nextArg:
    cmp     ecx, 0h         ; compara los argumentos hasta encontrar el caracter nulo
    jz      noMoreArgs      ; cuando encuentre el caracter nulo salta a la etiqueta noMoreArgs
    pop     eax             ; saca los argumentos de la pila
    call    sprintLF        ; manda a llamar a la funcion sprintLF(line feed) es decir con salto de linea
    dec     ecx             ; disminuye 1 exc
    jmp     nextArg         ; salta a la etiqueta NextArg
 
noMoreArgs:
    call    quit