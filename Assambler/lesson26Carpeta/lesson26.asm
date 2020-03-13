; Close
; Compile with: nasm -f elf lesson26.asm
; Link with (64 bit systems require elf_i386 option): ld -m elf_i386 lesson26.o -o lesson26
; Run with: ./lesson26
 
%include    'lesson16Func.asm'
 
SECTION .data
filename db 'readme.txt', 0h    ; the filename to create
contents db 'Hello world!', 0h  ; the contents to write
 
SECTION .bss
fileContents resb 255,          ; variable to store file contents
 
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
 
    mov     edx, 12             ; prepara el numero de bytes a leer
    mov     ecx, fileContents   ; mueve nuestra direccion de memoria de nuuestra variable de contenido del archivo a ecx
    mov     ebx, eax            ; mueve el valor de retorno de sys open a ebx
    mov     eax, 3              ; llama SYS_READ (kernel opcode 3)
    int     80h                 ; crea una interrupcion para que se ejecute el comando anterior
 
    mov     eax, fileContents   ; mueve la el contenido del archivo a eax para mandarlo a imprimir despues
    call    sprintLF            ; manda a imprimir un string con un salto de linea
 
    mov     ebx, ebx            ; apunta el registro de ebx a ebx
    mov     eax, 6              ; llama SYS_CLOSE (kernel opcode 6) para cerrar el archivo correctamente
    int     80h                 ;  crea una interrupcion para que se ejecute el comando anterior
 
    call    quit                ; llama a la funcion de terminar el programa