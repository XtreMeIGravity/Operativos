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