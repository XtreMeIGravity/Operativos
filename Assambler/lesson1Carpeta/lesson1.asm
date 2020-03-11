; Hello World Program - asmtutor.com
; Compile with: nasm -f elf lesson1.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson1.o -o lesson1
; Run with: ./lesson1
 
SECTION .data   ;seccion de constantes o valores definidos
msg     db      'Hello World!', 0Ah     ; msg nombre de variable db doubleyte<-tam    
                                        ; cadena con un salto de linea al final (0Ah)
 
SECTION .text   ;seccion del programa
global  _start  ;inicio del programa definicion
 
_start:         ;funcion o inicio del programa definido
 
    mov     edx, 13     ; la longiutud de la pantalla incluyendo el caracter
    
    mov     ecx, msg    ; lo que yo quiero mandar a impresion

    mov     ebx, 1      ; hacia donde envia la operacion(pantalla) stdout=1

    mov     eax, 4      ; operacion de escritura stdWrite()eax=4

    int     80h         ; Una interrupcion que le dice al microprocesador ejecuta el 
                        ; comando marcado en la linea anterior casi todas las operaciones 
                        ; usan el registro eax