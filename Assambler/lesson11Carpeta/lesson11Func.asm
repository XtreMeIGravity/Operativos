;------------------------------------------
; void iprint(Integer number)
; Integer printing function (itoa)
iprint:
    push    eax             ; almacena el valor del registro en el stack
    push    ecx             ; almacena el valor del registro en el stack
    push    edx             ; almacena el valor del registro en el stack
    push    esi             ; almacena el valor del registro en el stack
    mov     ecx, 0          ; almacena el valor 0 en ecx
 
divideLoop:
    inc     ecx             ; incrementa 1 en ecx cada division
    mov     edx, 0          ; almacena 0 en edx
    mov     esi, 10         ; almacena 10 en esi
    idiv    esi             ; DVIDIDE EAX SOBRE ESI y el residuo se almacena sobre edx
    add     edx, 48         ; le suma 48 a edx para convertilo a su correspondiente digito en ascii
    push    edx             ; almacena el valor de edx , resultado de la division despues de sumarle 48 de ascci
    cmp     eax, 0          ; compara el valor de eax, el resultado de la division con 0
    jnz     divideLoop      ; esto se repetira hasta que eax quede en 0 g
 
printLoop:
    dec     ecx             ; deciende en 1 para imprimir los valores aumentados en la etiqueta anterior
                            ; ya que va dividiendo sobre 10 en este caso
    mov     eax, esp        ; busca el valor de eax en el stack y lo restaura
    call    sprint          ; llama a la funcion sprint
    pop     eax             ; saca los valores en eax del stack
    cmp     ecx, 0          ; compara hasta que el contador quede en 0
    jnz     printLoop       ; esto se repetira hasta que ecx quede en 0 
 
    pop     esi             ; regresa los valores de los registros 
    pop     edx             ; restore edx from the value we pushed onto the stack at the start
    pop     ecx             ; restore ecx from the value we pushed onto the stack at the start
    pop     eax             ; restore eax from the value we pushed onto the stack at the start
    ret
 
 
;------------------------------------------
; void iprintLF(Integer number)
; Integer printing function with linefeed (itoa)
iprintLF:
    call    iprint      ; llama la funcion imprimir enteros

    push    eax         ; manda al stack(Pila) el valor de eax
    mov     eax, 0Ah    ; agrega 0Ah que equivale a un salto de linea  en ascii
    push    eax         ; manda al stack(Pila) el valor de eax ( un salto de linea)
    mov     eax, esp    ; mueve el apuntador de la pila hacia el que se guarda eax(oah)
    call    sprint      ; manda a llamar a la funcion sprint 
    pop     eax         ; restaura el ultimo valor almacenado de eax (0Ah)
    pop     eax         ; restaura el ultimo valor almacenado de eax la cadena a imprimir 
    ret                 ; vuelve a donde se mando a llamar a la etiqueta sprintLF
                        ;con el comando  call

 ;------------------------------------------
; int slen(String message)
; String length calculation function
slen:
    push    ebx         ; en caso de que ebx tenga un valor almacenado lo mandara al stack
    mov     ebx, eax    ; apunta ebx (el ya vacio) a el msg o dato a imprimir
    
nextchar:
    cmp     byte [eax], 0   ; compara y toma el primer byte del apuntador 
                            ; y lo compara con el valor (cadena) 0 que esta hasta el final
    jz      finished        ; si es zero salta a la etiqueta finished
    inc     eax             ; incrementa el apuntoador eax lo que hace que apunte al siguiente caracter
    jmp     nextchar        ; salta a la etiqueta nextchar
 
finished:
    sub     eax, ebx        ; resta eax-ebx y este se almacena en eax
    pop     ebx             ; por ultimo se libera el registro ebx
                            ; trayendo el ultimo valor de ebx de la pila
    ret                     ; vuelve a donde se mando a llamar a la etiqueta superior
                            ; con el comando  call
 
;------------------------------------------
; void sprint(String message)
; String printing function
sprint:
    push    edx         ; manda al stack(Pila) el valor de edx
    push    ecx         ; manda al stack(Pila) el valor de ecx
    push    ebx         ; manda al stack(Pila) el valor de ebx
    push    eax         ; manda al stack(Pila) el valor de eax
    call    slen        ; llama a la funcion slen esta deja en el registro eax la longitud de la cadena
 
    mov     edx, eax    ;finalmente en este registro se guarda la longitud y opera 
    pop     eax         ;Regresa el valor de eax del stack(pila) debido a que el que se requeria cumplio
                        ;su funcion
 
    mov     ecx, eax    ;eax apunta  a la cadena es decir (msg)
    mov     ebx, 1      ; hacia donde envia la operacion(pantalla) stdout=1
    mov     eax, 4      ; operacion de escritura stdWrite()eax=4
    int     80h         ; Una interrupcion que le dice al microprocesador ejecuta el 
                        ; comando marcado en la linea anterior casi todas las operaciones 
                        ; usan el registro eax
    pop     ebx         ;Regresa el valor de ebx del stack(pila)
    pop     ecx         ;Regresa el valor de ecx del stack(pila)
    pop     edx         ;Regresa el valor de edx del stack(pila)
                        ;COMO PODEMOS OBSERVAR ES EN ORDEN OPUESTO AL QUE SE METIERON, esto
                        ;debido a que la estructura del tipo LIFO
    ret                 ;vuelve a donde se mando a llamar a la etiqueta sprint
                        ;con el comando  call
 
 
;------------------------------------------
; void sprintLF(String message)
; Imprime una cadena añadiendo un satlo de linea 
sprintLF:
    call    sprint      ; manda a llamar a la funcion sprint , que imprime la cadena como tal
 
    push    eax         ; manda al stack(Pila) el valor de eax
    mov     eax, 0Ah    ; agrega 0Ah que equivale a un salto de linea  en ascii
    push    eax         ; manda al stack(Pila) el valor de eax ( un salto de linea)
    mov     eax, esp    ; mueve el apuntador de la pila hacia el que se guarda eax(oah)
    call    sprint      ; manda a llamar a la funcion sprint 
    pop     eax         ; restaura el ultimo valor almacenado de eax (0Ah)
    pop     eax         ; restaura el ultimo valor almacenado de eax la cadena a imprimir 
    ret                 ; vuelve a donde se mando a llamar a la etiqueta sprintLF
                        ;con el comando  call
 
 
;------------------------------------------
; funcion exit() del programa
; termina el programa de forma correcta
quit:
    mov     ebx, 0      ; tu valor de retorno es 0
    mov     eax, 1      ;manda a llamar la funcion de SYS_EXIT
    int     80h         
    ret                 ;vuelve a donde se mando a llamar a la etiqueta quit
                        ;con el comando  call