; Open
; Compile with: nasm -f elf lesson24.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson24.o -o lesson24
; Run with: ./lesson24
 
%include    'lesson16Func.asm'
 
SECTION .data
filename db 'readme.txt', 0h    ; el nombre del archivo a crear
contents db 'Hello world!', 0h  ; lo que se va a escribir en el archivo
 
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
 
    mov     ecx, 0              ; Entre los modos de acceso a archivos, los más utilizados son: solo lectura (0),
                                ; solo escritura (1) y lectura-escritura (2).
    mov     ebx, filename       ; descripcion del archivo
    mov     eax, 5              ; llama  SYS_OPEN (kernel opcode 5)
                                ; La llamada al sistema devuelve el descriptor de archivo del archivo 
                                ; creado en el registro EAX, en caso de error, el código de error está en el registro EAX.
    int     80h                 ; crea una interrupcion para que se ejecute el comando anterior
 
    call    iprintLF            ; llama a funcion de imprimir entero con un salto de linea
                                ; En caso de que que se logre con exito retornara un valor positivo en el registro eax
                                ; en caso de error devuelve -1 y no se crea ni se modifica 
    call    quit                ; llama a la funcion de terminar el programa