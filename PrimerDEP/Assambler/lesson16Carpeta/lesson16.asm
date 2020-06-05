; Calculator (ATOI)
; Compile with: nasm -f elf lesson16.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson16.o -o lesson16
; Run with: ./lesson16 20 1000 317
 
%include        'lesson16Func.asm'
 
SECTION .text
global  _start
 
_start:                     ;Etiqueta de inicio del programa
 
    pop     ecx             ; almacena en la pila el numero de argumentos del programa
    pop     edx             ; el segundo valor en la pila es el nombre del programa (descartado cuando inicializamos edx)
    sub     ecx, 1          ; resta 1 al registro ecx para eliminar el arg
    mov     edx, 0          ; Almacenamos un 0 en dec  en el regiistro edx
 
nextArg:
    cmp     ecx, 0h         ; Revisa si quedan argumentos ya que al final de un programa existe un caracter nulo  Programa arg1 arg2 arg3 0h
    jz      noMoreArgs      ; cuando se cumple esta condicion salta a la etiqueta NoMoreArg
    pop     eax             ; expulsa de la pila el argumento siguiente al registro eax 
    call    atoi            ; llama la funcion que convierte el ascci en decimal 
    add     edx, eax        ; suma el argumento despues de convertirlo en Decimal, la operacion anterior trabaja sobre el registro eax
    dec     ecx             ; decrementa ecx (el numero de argumentos)
    jmp     nextArg         ; salta a la etiqueta nextArg
 
noMoreArgs:
    mov     eax, edx        ; mueve el resultado almacenado al registro eax
    call    iprintLF        ; Imprime el resultado
    call    quit            ; FInaliza el programa