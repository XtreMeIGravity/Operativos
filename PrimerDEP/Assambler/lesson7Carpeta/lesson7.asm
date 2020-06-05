; Hello World Program (Print with line feed)
; Compile with: nasm -f elf lesson7.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson7.o -o lesson7
; Run with: ./lesson7
 
%include        'lesson7Func.asm'   ;Incluye el archivo como si formara parte del programa
                                    ;En este caso incluye las funciones sprin, quit y sprintLF
 
SECTION .data   ;seccion de constantes
msg1    db      'Hello, brave new world!', 0h           ; msg1 nombre de variable
                                                        ; db(doubleyte)<-tamaño
                                                        ; y la finaliza con un caracter vacio (0h)
msg2    db      'This is how we recycle in NASM.', 0h   ; msg2 nombre de variable
                                                        ; db(doubleyte)<-tamaño
                                                        ; y la finaliza con un caracter vacio (0h)
 
SECTION .text
global  _start
 
_start:
 
    mov     eax, msg1   ; apunta el registro eax a msg ya que para sprint requiere que este en eax
    call    sprintLF     ; manda a llamar a la funcion sprintLF la cual incluye un salto de linea al final
 
    mov     eax, msg2   ; apunta el registro eax a msg ya que para sprint requiere que este en eax
    call    sprintLF     ; manda a llamar a la funcion sprint
 
    call    quit