#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <errno.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAX_COUNT 50

// Prototipos de los procesos padre e hijo 
void ProcesoHijo (void); 
void ProcesoPadre (void); 
int main (void) { 
    pid_t pid; 
    pid = fork(); 
    if (pid == 0)     
        ProcesoHijo(); 
    else     
        ProcesoPadre(); 
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

    /*Debido a que estos procesos se ejecutan de forma concurrente, 
    sus líneas de salida se entremezclan de forma aleatoria, sin orden predecible. 
    El orden lo determina el planificador de CPU. 
    Cada vez que se ejecuta este programa nos dará unos resultados diferentes pero en este caso 
    con dos funciones completamente diferentes, todo se basara en planificador del CPU*/
