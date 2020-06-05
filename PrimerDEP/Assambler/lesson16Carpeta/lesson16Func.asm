;------------------------------------------
; int atoi(Integer number)
; Ascii a Entero
atoi:
    push    ebx             ; Almacena el valor del registro en el stack
    push    ecx             ; Almacena el valor del registro en el stack
    push    edx             ; Almacena el valor del registro en el stack
    push    esi             ; Almacena el valor del registro en el stack
    mov     esi, eax        ; mueve el valor del apuntador de eax(numero que deseamos convertir)
                            ; a esi
    mov     eax, 0          ; Mete el al registro un valor de 0 a eax
    mov     ecx, 0          ; Mete el al registro un valor de 0 a ecx
 
.multiplyLoop:
    xor     ebx, ebx        ; Limpia el registro    
    mov     bl, [esi+ecx]   ; mueve un solo byte a la mitad inferior del byte
    cmp     bl, 48          ; compara el valor inferior del registro con el valor ascci 48 ( en simbolo equivale a 0)
    jl      .finished       ; salta a la etiqueta finshied para terminar la funcion si esta es menor
    cmp     bl, 57          ; compara el mismo valor inferior del registro con el valor ascci 57( en simbolo equivale a 9)
    jg      .finished       ; salta a la etiqueta finshied para terminar la funcion si esta es menor
 
    sub     bl, 48          ; convierte la cadena de entrada en ascii , le resta 48 para operarlo
    add     eax, ebx        ; suma el valor del registro ebx + eax
    mov     ebx, 10         ; mete al registro un valor de 10 en decimal en ebx
    mul     ebx             ; multiplica ebx por eax y el resultado se almacena en eax
    inc     ecx             ; incremente el valor de exc
    jmp     .multiplyLoop   ; salta a la etiqueta multiplityloop
 
.finished:
    mov     ebx, 10         ; mete al registro un valor de 10 en decimal en ebx
    div     ebx             ; divide el valor ebx sobre eax y el resultado lo guarda en eax
    pop     esi             ; Restaura los valores almacenados en el stack de forma opuesta a como se metieron
                            ; esto por la estructura (PILA)
    pop     edx             
    pop     ecx             
    pop     ebx             
    ret                     ;Regresa a la referencia en el stack al llamar la funcion call
;------------------------------------------
; void iprint(Integer number)
; Integer printing function (itoa)
iprint:
    push    eax             ; preserve eax on the stack to be restored after function runs
    push    ecx             ; preserve ecx on the stack to be restored after function runs
    push    edx             ; preserve edx on the stack to be restored after function runs
    push    esi             ; preserve esi on the stack to be restored after function runs
    mov     ecx, 0          ; counter of how many bytes we need to print in the end
 
divideLoop:
    inc     ecx             ; count each byte to print - number of characters
    mov     edx, 0          ; empty edx
    mov     esi, 10         ; mov 10 into esi
    idiv    esi             ; divide eax by esi
    add     edx, 48         ; convert edx to it's ascii representation - edx holds the remainder after a divide instruction
    push    edx             ; push edx (string representation of an intger) onto the stack
    cmp     eax, 0          ; can the integer be divided anymore?
    jnz     divideLoop      ; jump if not zero to the label divideLoop
 
printLoop:
    dec     ecx             ; count down each byte that we put on the stack
    mov     eax, esp        ; mov the stack pointer into eax for printing
    call    sprint          ; call our string print function
    pop     eax             ; remove last character from the stack to move esp forward
    cmp     ecx, 0          ; have we printed all bytes we pushed onto the stack?
    jnz     printLoop       ; jump is not zero to the label printLoop
 
    pop     esi             ; restore esi from the value we pushed onto the stack at the start
    pop     edx             ; restore edx from the value we pushed onto the stack at the start
    pop     ecx             ; restore ecx from the value we pushed onto the stack at the start
    pop     eax             ; restore eax from the value we pushed onto the stack at the start
    ret
 
 
;------------------------------------------
; void iprintLF(Integer number)
; Integer printing function with linefeed (itoa)
iprintLF:
    call    iprint          ; call our integer printing function
 
    push    eax             ; push eax onto the stack to preserve it while we use the eax register in this function
    mov     eax, 0Ah        ; move 0Ah into eax - 0Ah is the ascii character for a linefeed
    push    eax             ; push the linefeed onto the stack so we can get the address
    mov     eax, esp        ; move the address of the current stack pointer into eax for sprint
    call    sprint          ; call our sprint function
    pop     eax             ; remove our linefeed character from the stack
    pop     eax             ; restore the original value of eax before our function was called
    ret
 
 
;------------------------------------------
; int slen(String message)
; String length calculation function
slen:
    push    ebx
    mov     ebx, eax
 
nextchar:
    cmp     byte [eax], 0
    jz      finished
    inc     eax
    jmp     nextchar
 
finished:
    sub     eax, ebx
    pop     ebx
    ret
 
 
;------------------------------------------
; void sprint(String message)
; String printing function
sprint:
    push    edx
    push    ecx
    push    ebx
    push    eax
    call    slen
 
    mov     edx, eax
    pop     eax
 
    mov     ecx, eax
    mov     ebx, 1
    mov     eax, 4
    int     80h
 
    pop     ebx
    pop     ecx
    pop     edx
    ret
 
 
;------------------------------------------
; void sprintLF(String message)
; String printing with line feed function
sprintLF:
    call    sprint
 
    push    eax
    mov     eax, 0AH
    push    eax
    mov     eax, esp
    call    sprint
    pop     eax
    pop     eax
    ret
 
 
;------------------------------------------
; void exit()
; Exit program and restore resources
quit:
    mov     ebx, 0
    mov     eax, 1
    int     80h
    ret