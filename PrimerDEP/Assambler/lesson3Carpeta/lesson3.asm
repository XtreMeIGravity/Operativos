; Hello World Program (Calculating string length)
; Compile with: nasm -f elf lesson3.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson3.o -o lesson3
; Run with: ./lesson3
 
SECTION .data
msg     db      'Hello, brave new world!', 0Ah  ; we can modify this now without having 
                                                ; to update anywhere else in the program

SECTION .text
global  _start
 
_start:                     ; Inicio del programa
 
    mov     ebx, msg        ; mueve la direccion de msg a el registro ebx 
    mov     eax, ebx        ; mueve la direccion de ebx(msg) a eax
 
nextchar:
    cmp     byte [eax], 0   ; compara y toma el primer byte del apuntador 
                            ; y lo compara con el valor (cadena) 0 que esta hasta el final
    jz      finished        ; si es zero salta a la etiqueta finished
    inc     eax             ; incrementa el apuntoador eax lo que hace que apunte al siguiente caracter
    jmp     nextchar        ; salta a la etiqueta nextchar
    
finished:
    sub     eax, ebx        ; una sustracion  siempre se almacena eax  , en esta caso 
                            ;resta el ultimo valor en memoria y lo pasa al primero
 
    mov     edx, eax        ;finalmente en este registro se guarda la longitud y opera 
    mov     ecx, msg        ; lo que yo quiero mandar a impresion se mandara al registro ecx
    mov     ebx, 1          ; hacia donde envia la operacion(pantalla) stdout=1
    mov     eax, 4          ; operacion de escritura stdWrite()eax=4
    int     80h             ; Una interrupcion que le dice al microprocesador ejecuta el 
                            ; comando marcado en la linea anterior casi todas las operaciones 
                            ; usan el registro eax

    mov     ebx, 0          ; tu valor de retorno es 0
    mov     eax, 1          ; manda a llamar la funcion de SYS_EXIT
    int     80h