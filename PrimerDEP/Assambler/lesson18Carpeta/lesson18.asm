; lesson18
; Compile with: nasm -f elf lesson18.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson18.o -o lesson18
; Run with: ./lesson18
 
%include        'lesson16Func.asm'
 
SECTION .data
fizz        db      'Fizz', 0h     ; Mensaje Fizz
buzz        db      'Buzz', 0h     ; Mensaje Buzz
 
SECTION .text
global  _start
                            
_start:
    ;Registros esi ,edi Se utilizan para copiar cadenas y matrices de memoria
    mov     esi, 0          ; Inicializa checkFizz variable booleana
    mov     edi, 0          ; Inicializa checkBuzz variable booleana
    mov     ecx, 0          ; Inicializa la variable del contador
 
nextNumber:
    inc     ecx             ; Incrementa el contador
 
.checkFizz
    mov     edx, 0          ; almacena un 0 en decimal en el registro edx para guardar el residuo de la division
    mov     eax, ecx        ; mueve el valor del contador a eax
    mov     ebx, 3          ; asigna un valor 3 dec al registro ebx
    div     ebx             ; el valor del contador sobre el 3 asignado en el registro anterior
    mov     edi, edx        ; mueve el residuo de la division (este se almacena en edx) y lo almacena
                            ; en el registro edi
    cmp     edi, 0          ; compara el residuo con 0 
    jne     .checkBuzz      ; si no es 0 ahora salta a la etiqueta checkBuzz SALTANDO LA IMPRESION DE FIZZ
                            ; ya que no es divisible entre 3
    mov     eax, fizz       ; en caso de que sea 0 quiere decir que si es divisible entre 3 
                            ; y prepara la impresion moviendo la cadena fizz a el registro eax
    call    sprint          ; llama  a la funcion sprint (Imprimir cadena)
 
.checkBuzz: 
    mov     edx, 0          ; almacena un 0 en decimal en el registro edx para guardar el residuo de la division
    mov     eax, ecx        ; mueve el valor del contador a eax
    mov     ebx, 5           ; asigna un valor 5 dec al registro ebx
    div     ebx             ; el valor del contador sobre el 5 asignado en el registro anterior
    mov     esi, edx        ; mueve el residuo de la division (este se almacena en edx) y lo almacena
                            ; en el registro esi
    cmp     esi, 0          ; compara el residuo con 0 
    jne     .checkInt       ; si no es 0 ahora salta a la etiqueta checkInt SALTANDO LA IMPRESION DE BUZZ
                            ; ya que no es divisible entre 5
    mov     eax, buzz       ; en caso de que sea 0 quiere decir que si es divisible entre 5 
                            ; y prepara la impresion moviendo la cadena Buzz a el registro eax
    call    sprint          ; llama  a la funcion sprint (Imprimir cadena)
 
.checkInt:
    cmp     edi, 0          ; compara el residuo con 0 de checkFizz(Divisible entre 3)
    je     .continue        ; si el residuo es igual a 0 salta a la etiquetaContinue
    cmp     esi, 0          ; compara el residuo con 0 de checkBuzz(Divisible entre 5)
    je     .continue        ; si el residuo es igual a 0 salta a la etiquetaContinue
    mov     eax, ecx        ; en caso de que no se cumplan los anteriores  prepara la impresion moviendo al registro eax
    call    iprint          ; llama a la funcion iprint(ImprimirEntero)
 
.continue:
    mov     eax, 0Ah        ; prepara un salto de linea para imprimir
    push    eax             ; manda el salto de linea al stack
    mov     eax, esp        ; obteiene el salto de linea almacenado en el stack
    call    sprint          ; Imprime el salto de linea
    pop     eax             ; regresa el valor del registro eax guardado en el stack
    cmp     ecx, 100        ; compara si el contador general es igual a 100
    jne     nextNumber      ; Si la condicion anterior no se cumple salta al principio incrementando el cotnador
 
    call    quit            ; llama a la funcion para terminar el programa