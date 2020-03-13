; Seek
; Compile with: nasm -f elf lesson27.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson27.o -o lesson27
; Run with: ./lesson27
 
%include    'lesson16Func.asm'
 
SECTION .data
filename db 'readme.txt', 0h    ; the filename to create
contents  db '-updated-', 0h     ; the contents to write at the start of the file
 
SECTION .text
global  _start
 
_start:
 
    mov     ecx, 1              ; Entre los modos de acceso a archivos, los más utilizados son: solo lectura (0),
                                ; solo escritura (1) y lectura-escritura (2).
    mov     ebx, filename       ; descripcion del archivo
    mov     eax, 5              ; llama  SYS_OPEN (kernel opcode 5)
                                ; La llamada al sistema devuelve el descriptor de archivo del archivo 
                                ; creado en el registro EAX, en caso de error, el código de error está en el registro EAX.
    int     80h                 ; crea una interrupcion para que se ejecute el comando anterior
 
    mov     edx, 2              ; argumento de puntero de SYS_LSEEK se coloca al final del texto
    mov     ecx, 0              ; Añade un 0 al registro ecx
    mov     ebx, eax            ; Guarda el descriptor del archivo
    mov     eax, 19             ; llama SYS_LSEEK (kernel opcode 19) que coloca el puntero en la posicion 
                                ; de edx
    int     80h                 ; crea una interrupcion para que se ejecute el comando anterior
 
    mov     edx, 9              ; numero de bytes a escribir
    mov     ecx, contents       ; mueve la cadena de contenido ecx
    mov     eax, 4              ; llama SYS_WRITE (kernel opcode 4)
    int     80h                 ; crea una interrupcion para que se ejecute el comando anterior
 
    call    quit                ; llama a la funcion de terminar el programa