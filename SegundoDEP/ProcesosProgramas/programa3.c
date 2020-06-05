#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h> 

void main (){   
    pid_t childpid; //Una variable para almacenar el PID del proceso  hijo creado 
    int status; 
    if ((childpid = fork()) == -1) {    /*RETORNA -1 en caso de error,                  
                                        si es el proceso hijo retorna 0 y el                  
                                        proceso padre retorna el PID (Process identifier) 
                                        asignado al proceso hijo y este se almacena en  childPID
                                        */        
                                       
                        
        perror ("Fork ha fallado");     
        exit(1);                        //Termina el programa en caso de que no se cree el proceso 
                                        //de forma correcta con fork
    } else if (childpid == 0)// identifica si es el proceso Hijo e Imprime su PID
        fprintf(stderr, "Soy el hijo con pid = %ld\n", (long)getpid()); 
    else if (wait(&status) != childpid) //wait retorna -1 en caso de fallo  Si algún proceso no tiene un proceso hijo devuelve inmediatamente "-1".
                                        // Si wait retorna 0 sabe que es un proceso hijo por lo que 
                                        // >0 significa esperar al hijo cuyo ID de proceso es igual a
                                        //<-1 significa esperar a cualquier proceso hijo cuyo ID de grupo de proceso sea valor de pid.
        fprintf (stderr, "Wait interrumpido por una señal\n"); 
    else // identifica si es el proceso padre e Imprime su PID
        fprintf (stderr, "Soy el padre con pid = %ld\n",(long)getpid());
    exit(0);
}