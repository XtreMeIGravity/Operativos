; lesson17
; Compile with: nasm -f elf lesson17.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson17.o -o lesson17
; Run with: ./lesson17
 
%include        'lesson16Func.asm'
 
SECTION .data
msg1        db      'Jumping to finished label.', 0h        ; Mensaje 1 con un carcater de final de cadena
msg2        db      'Inside subroutine number: ', 0h        ; Mensaje 2 con un carcater de final de cadena
msg3        db      'Inside subroutine "finished".', 0h     ; Mensaje 3 con un carcater de final de cadena
 
SECTION .text
global  _start
 
_start:
 
subrountineOne:             ; ETIQUETA:Subrutina 1
    mov     eax, msg1       ; Mueve la direccion de memoria de msg1 a eax 
    call    sprintLF        ; Llama a la funcion sprintLF la cual requiere que lo que
                            ; va a imprimir este en  en el registro eax
    jmp     .finished       ; salta a la etiqueta .finished (en este caso acude a la que este en
                            ; mas proxima o pertenezca a esta funcion
 
.finished:                  ; ETIQUETA: .finished
    mov     eax, msg2       ; mueve la direcion de memoria del msg 2 a el registro eax
    call    sprint          ; Llama a la funcion sprint ,la cual imprime sin un salto de linea
                            ; esta cadena inclye "subrutina numero:"
    mov     eax, 1          ; coloca un 1 dec en el registro eax
    call    iprintLF        ; Imprime el valor en entero del registro eax
 
subrountineTwo:             ; ETIQUETA:Subrutina 2
    mov     eax, msg1       ; Mueve la direccion de memoria de msg a eax 
    call    sprintLF        ; Llama a la funcion sprintLF la cual requiere que lo que
                            ; va a imprimir este en  en el registro eax
    jmp     .finished       ; salta a la etiqueta .finished (en este caso acude a la que este en
                            ; mas proxima o pertenezca a esta funcion
 
.finished:                  ; ETIQUETA: .finished
    mov     eax, msg2       ; mueve la direcion de memoria del msg1 2 a el registro eax
    call    sprint          ; Llama a la funcion sprint ,la cual imprime sin un salto de linea
                            ; esta cadena inclye "subrutina numero:"
    mov     eax, 2          ; coloca un 2 dec en el registro eax
    call    iprintLF        ; Imprime el valor en entero del registro eax
 
    mov     eax, msg1       ; Mueve la direccion de memoria de msg1 a eax
    call    sprintLF        ; llama a la funcion imprimir string con salto de linea
    jmp     finishedP       ; se va a la etiqueta finishedP 
 
finishedP:
    mov     eax, msg3       ; Mueve la direccion de memoria de msg3 a eax
    call    sprintLF        ; llama a la funcion imprimir string con salto de linea
    call    quit            ; llama a la funcion salir , que se encarga de que el programa termine 
                            ; correctamente