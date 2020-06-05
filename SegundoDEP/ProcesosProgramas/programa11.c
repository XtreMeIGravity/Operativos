#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <errno.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAX_COUNT 200 
#define BUF_SIZE 100 
// Prototipo del proceso hijo 
void ProcesoHijo(char *, char *); 
int main (void) { 
    pid_t pid1, pid2, pid; 
    int status; 
    int i; 
    char buf[BUF_SIZE]; 
    printf("*** El proceso padre realiza el fork() - 1 ***\n"); 
    pid1 = fork(); 
    if (pid1 < 0) {    
        printf("Fallo al crear proceso 1\n");    
        exit(1);    
    }    
    if (pid1 == 0) {    
        ProcesoHijo("Primero", " ");    
    }    
    printf("*** El proceso padre realiza el fork() - 2 ***\n"); 
    pid2 = fork(); 
    if (pid2 < 0) {    
        printf("Fallo al crear proceso 2\n");    
        exit(1);    
    }    
    if (pid2 == 0) {    
        ProcesoHijo("Segundo", " ");    
    }    
    sprintf(buf, "*** El padre entra en estado de espera .....\n"); 
    write(1, buf, strlen(buf)); 
    pid = wait(&status); 
    sprintf(buf, "*** El padre ha detectado que el proceso hijo %d ha terminado ***\n", pid); 
    write(1, buf, strlen(buf)); 
    pid = wait(&status); 
    printf("*** El padre ha detectado que el proceso hijo %d ha terminado ***\n", pid); 
    printf("*** El proceso padre termina *** \n"); 
    exit(0); 
} 
void ProcesoHijo(char *number, char *space) { 
    pid_t pid; 
    int i; 
    char buf[BUF_SIZE]; 
    pid = getpid(); 
    sprintf(buf, "%sEl proceso hijo %s comienza (pid = %d)\n", space, number, pid); 
    write(1, buf, strlen(buf)); 
    for (i=1; i<=MAX_COUNT; i++) {     
        sprintf(buf, "%sSalida del proceso hijo %s, Valor=%d\n", space, number, i);     
        write(1, buf, strlen(buf));     
    }
    sprintf(buf, "%sEl proceso hijo %s (pid = %d) va a terminar\n", space, number, pid); 
    write(1, buf, strlen(buf)); 
    exit(0); 
}