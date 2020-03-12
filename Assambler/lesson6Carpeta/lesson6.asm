; Hello World Program (External file include)
; Compile with: nasm -f elf lesson5.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson5.o -o lesson5
; Run with: ./lesson5
 
%include        'lesson5Func.asm'   ;Incluye el archivo como si formara parte del programa
                                    ;En este caso incluye las funciones sprint  y quit
 
SECTION .data   ;seccion de constantes
msg1    db      'Hello, brave new world!', 0Ah ,0h             ; msg1 nombre de variable
                                                            ; db(doubleyte)<-tamaño
                                                            ; cadena con un salto de linea al final (0Ah)
                                                            ; y la finaliza con un caracter vacio (0h)
msg2    db      'This is how we recycle in NASM.', 0Ah,0h      ; msg2 nombre de variable
                                                            ; db(doubleyte)<-tamaño
                                                            ; cadena con un salto de linea al final (0Ah)
                                                            ; y la finaliza con un caracter vacio (0h)
        
SECTION .text
global  _start
 
_start:
 
    mov     eax, msg1       ; apunta el registro eax a msg ya que para sprint requiere que este en eax
    call    sprint          ; manda a llamar a la funcion sprint
 
    mov     eax, msg2       ; apunta el registro eax a msg ya que para sprint requiere que este en eax
    call    sprint          ; manda a llamar a la funcion sprint
 
    call    quit            ; manda a llamar a la funcion quit