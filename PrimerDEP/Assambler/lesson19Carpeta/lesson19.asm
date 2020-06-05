; Execute
; Compile with: nasm -f elf lesson19.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson19.o -o lesson19
; Run with: ./lesson19
 
%include        'lesson16Func.asm'
 
SECTION .data
command         db      '/bin/echo', 0h     ; el comando que se va ejecutar
arg1            db      'Hello World!', 0h  ;  argumento del comando 
;crea una estructura con tipos de dato defined double word Generalmente 4 bytes en un sistema de 32 bits 
arguments       dd      command             ; el comando que se va ejecutar
                dd      arg1                ; argumentos que pasaran a la linea de comandos
                dd      0h                  ; indica el final de la estructura
environment     dd      0h                  ; el argumento pasa a ser variable de entorno 
 
SECTION .text
global  _start
 
_start:
 
    mov     edx, environment    ; apunta  a la direccion de la variable enviroment 
    mov     ecx, arguments      ; carga el comando en la linea de comandos
    mov     ebx, command        ; direcciona el arhivo donde se encuentra el comando
    mov     eax, 11             ; invoca SYS_EXECVE (que corresponde a la opcion numero 11)
    int     80h                 ;crea la interrupcion en el microporcesador para que se ejecute la ultima opcion
 
    call    quit                ; llama a la funcion quit que se encarga de terminar el programa correctamente  