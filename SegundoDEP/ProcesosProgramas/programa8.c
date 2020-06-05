#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <errno.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAX_COUNT 50 
#define BUF_SIZE 100 

int main(void) { 
    pid_t pid;  
    int i;  
    char buf[BUF_SIZE]; 
    fork(); 
    pid = getpid(); 
    for (i = 1; i <= MAX_COUNT; i++) {     
        sprintf(buf, "Esta línea la ha imprimido PID: %d, Valor=%d\n", pid, i);     
        write(1, buf, strlen(buf));     
        /*La razón para utilizar write en vez de printf es porque printf utiliza un buffer, 
        es decir, printf agrupa todas sus salidas para mostrarlas de golpe.*/
    }
    /*Debido a que estos procesos se ejecutan de forma concurrente, 
    sus líneas de salida se entremezclan de forma aleatoria, sin orden predecible. 
    El orden lo determina el planificador de CPU. 
    Cada vez que se ejecuta este programa nos dará unos resultados diferentes*/
}