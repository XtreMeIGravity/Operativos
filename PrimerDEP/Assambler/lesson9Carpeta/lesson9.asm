; Hello World Program (Getting input)
; Compile with: nasm -f elf lesson9.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson9.o -o lesson9
; Run with: ./lesson9
 
%include        'lesson7Func.asm'
 
SECTION .data   ;seccion de constantes
msg1        db      'Please enter your name: ', 0h      ; mensaje 1 , entrada del nombre 
msg2        db      'Hello, ', 0h                       ; mensaje 2
 
SECTION .bss    ;seccion de variables
sinput:     resb    255                                 ; Reserva 255 bytes 
 
SECTION .text   ;seccion del programa
global  _start
 
_start:
 
    mov     eax, msg1       ; apunta el registro eax a msg ya que para sprint requiere que este en eax
    call    sprint           ; manda a llamar a la funcion sprint esta no inclye un salto de linea
 
    mov     edx, 255        ; escribe un 255 sobre el registro edx
    mov     ecx, sinput     ; reserved space to store our input (known as a buffer)
    mov     ebx, 0          ; stdin=0  , prepara la entrada
    mov     eax, 3          ; manda a llamar la funcion de SYS_READ
    int     80h             ; Crea una interrupcion para ejecutar lo anterior
 
    mov     eax, msg2       ; apunta el registro eax a msg2 ya que para sprint requiere que este en eax
    call    sprint          ; manda a llamar a la funcion sprint esta no inclye un salto de linea
 
    mov     eax, sinput     ; apunta el registro eax a msg2 ya que para sprint requiere que este en eax
    call    sprint          ; manda a llamar a la funcion sprint esta no inclye un salto de linea
 
    call    quit