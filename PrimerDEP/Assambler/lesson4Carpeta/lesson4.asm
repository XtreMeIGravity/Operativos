; Hello World Program (Subroutines)
; Compile with: nasm -f elf lesson4.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson4.o -o lesson4
; Run with: ./lesson4
 
SECTION .data   ;seccion de constantes
msg     db      'Hello, brave new world!', 0Ah      ; msg nombre de variable
                                                    ; db(doubleyte)<-tamaño
                                                    ; cadena con un salto de linea al final (0Ah)
 
SECTION .text   ;seccion del programa
global  _start
 
_start:
 
    mov     eax, msg        ; apunta el registro eax a msg
    call    strlen          ; Llama a la etiqueta strlen que funcionará 
                            ; como una función (saltar a la etiqueta correspondiente)
 
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
 
strlen:                     ; La etiqueta strlen mencionada antes
    push    ebx             ; en caso de que ebx tenga un valor almacenado lo mandara al stack
                            ; Un Stack es una estructura dentro de la memoria del tipo LIFO
                            ; Last Input First Output (Ultimo en entrar Primero en salir)
    mov     ebx, eax        ; apunta ebx (el ya vacio) a el msg
 
nextchar:
    cmp     byte [eax], 0   ; compara y toma el primer byte del apuntador 
                            ; y lo compara con el valor (cadena) 0 que esta hasta el final
    jz      finished        ; si es zero salta a la etiqueta finished
    inc     eax             ; incrementa el apuntoador eax lo que hace que apunte al siguiente caracter
    jmp     nextchar        ; salta a la etiqueta nextchar
 
finished:                   ; etiqueta finished
    sub     eax, ebx        ; resta eax-ebx y este se almacena en eax
    pop     ebx             ; por ultimo se libera el registro ebx
                            ; trayendo el ultimo valor de ebx de la pila
    ret                     ; vuelve a donde se mando a llamar a la etiqueta superior
                            ; con el comando  call