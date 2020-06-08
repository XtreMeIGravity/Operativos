; Calculator (Division)
; Compile with: nasm -f elf lesson15.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson15.o -o lesson15
; Run with: ./lesson15
 
%include        'lesson11Func.asm'
 
SECTION .data
msg1        db      ' remainder '      ; a message string to correctly output result
 
SECTION .text
global  _start
 
_start:
 
    mov     eax, 95     ; almacena un 90 en eax
    mov     ebx, 9      ; almacena un 9 en ebx
    div     ebx         ; divide eax sobre ebx y lo almacena en eax y el residuo se queda en edx
    call    iprint      ; Imprime un entero 
    mov     eax, msg1   ; apunta el registro eax a msg ya que para sprint requiere que este en eax
    call    sprint      ; manda a llamar a la funcion sprint
    mov     eax, edx    ; en edx queda el residuo de la division
    call    iprintLF    ; Imprime un entero con salto de linea
    call    quit