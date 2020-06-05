#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <errno.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

// Función para imprimir información sobre un proceso 
void PrintInfo (pid_t pid) {   
    printf ("PID=%d PPID=%d\r\n",getpid(),getppid() );   
    printf ("UID=%d GID=%d\r\n",getuid(),getgid() );   
    printf ("EUID=%d EGID=%d\r\n",geteuid(), getegid() );   
    printf ("PGRP=%d\r\n",getpgrp() );   
}   
int main() { 
    pid_t pid; 
    pid = fork(); 
    // Creamos proceso hijo 
    printf ("Valor retornado por la llamada fork: %d\n",pid); 
    switch (pid) {   
        case -1: // Se ha producido error        
        printf ("No se ha podido crear el proceso hijo\n");        
        exit(1); // Salimos indicando la situación   
        case 0: // Estamos en el proceso hijo        
            printf ("\n** PROCESO HIJO **\n");        
            // Utilizamos getppid() para obtener el PID del padre           
            // Utilizamos getpid para obtener el PID del hijo (actual)     
            PrintInfo (pid);        /* ... */        
        break;    
        default: /* Estamos en el proceso padre: pid>0 */       
            printf ("\r\n** PROCESO PADRE **\r\n");        
            // Utilizamos getpid() para obtener el PID del padre              
            // El PID del hijo será lo que devolvió fork()         
            PrintInfo (pid);        /* ... */    
    }    
} 