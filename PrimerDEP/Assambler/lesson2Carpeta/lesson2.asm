; Hello World Program - asmtutor.com
; Compile with: nasm -f elf lesson2.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson2.o -o lesson2
; Run with: ./lesson2clear

SECTION .data   ;seccion de constantes
msg     db      'Hello World!', 0Ah     ; msg nombre de variable
                                        ; db(doubleyte)<-tamaño
                                        ; cadena con un salto de linea al final (0Ah)

SECTION .text   ;seccion del programa
global  _start  ;inicio del programa definicion

_start:         ;funcion o inicio del programa definido

    mov     edx, 13     ; la longiutud de la cadena(msg) incluyendo el caracter de salto de linea
    mov     ecx, msg    ; lo que yo quiero mandar a impresion se mandara al registro ecx
    mov     ebx, 1      ; hacia donde envia la operacion(pantalla) stdout=1
    mov     eax, 4      ; operacion de escritura stdWrite()eax=4
    int     80h         ; Una interrupcion que le dice al microprocesador ejecuta el 
                        ; comando marcado en la linea anterior casi todas las operaciones 
                        ; usan el registro eax

    mov     ebx, 0      ; tu valor de retorno es 0
    mov     eax, 1      ; manda a llamar la funcion de SYS_EXIT
    int     80h