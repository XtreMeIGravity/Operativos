#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <errno.h> 
#include <stdio.h> 
#include <stdlib.h>
#define MAX_COUNT 50

// Prototipos de los procesos padre e hijo 
void ProcesoHijo (void); 
void ProcesoPadre (void); 
void main(void) { 
    pid_t pid; 
    pid = fork(); 
    if (pid == 0){ 
        ProcesoHijo(); 
    }else {    
        ProcesoPadre();  
        // Si no nos interesa el valor del estado debemos poner el puntero nulo NULL    
        wait(NULL);    
        /*Espera a que termine el proceso padre para ejecutar el proceso hijo
        en el caso de que el proceso hijo termine antes de que el padre haya ejecutado 
        el wait, el proceso hijo se queda en un estado denominado "zombie", hasta que 
        el padre ejecute wait, momento en que se destruye el hijo.
        */
    }    
}
void ProcesoHijo (void) { 
    int i; 
    for (i=1; i<=MAX_COUNT; i++)     
        printf("Esta linea la ha imprimido el proceso HIJO, Value=%d\n", i);
    printf(" *** El proceso hijo ha terminado ***\n"); 
} 
void ProcesoPadre (void) { 
    int i; 
    for (i=1; i<=MAX_COUNT; i++)     
        printf("Esta linea la ha imprimido el proceso PADRE, Value=%d\n", i); 
    printf("*** El proceso padre ha terminado ***\n"); 
} 