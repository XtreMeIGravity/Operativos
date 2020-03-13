; Write
; Compile with: nasm -f elf lesson23.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson23.o -o lesson23
; Run with: ./lesson23
 
%include    'lesson16Func.asm'
 
SECTION .data
filename db 'readme.txt', 0h    ; the filename to create
contents db 'Hello world!', 0h  ; the contents to write
 
SECTION .text
global  _start
 
_start:
 
    mov     ecx, 0777           ; Establece los permisos de lectura , escrituras y  ejecucion 
    mov     ebx, filename       ; filename we will create
    mov     eax, 8              ; llama a sys_creat
    int     80h                 ; crea una interrupcion para que se ejecute el comando anterior
 
    mov     edx, 12             ; Numero de bytes de nuestra cadena a escribir en el archivo
    mov     ecx, contents       ; Prepara la cadena para escribirla en el archivo
    mov     ebx, eax            ; mueve el archivo creado anterior mente a ebx 
    mov     eax, 4              ; LLama SYS_WRITE para escribir sobre la descripcion almacenada en ebx
    int     80h                 ; crea una interrupcion para que se ejecute el comando anterior
 
    call    quit                ; llama a la funcion de terminar el programa
