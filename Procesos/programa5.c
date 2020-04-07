#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <errno.h> 
#include <stdio.h> 
#include <stdlib.h>

void main(int argc, char *argv[]) { 
    pid_t childpid; 
    int status; 
    if (childpid = fork() == -1) {    
        perror("Fork ha fallado");    
        exit(1);    
    } else if (childpid == 0) { /*codigo del hijo*/         
        if (execvp(argv[1], &argv[1]) < 0) { //no retornana nada si tienen  éxito, -1 si error
            perror("exec ha fallado");       
            exit(1);             
        }     
    } else /*codigo del padre*/    
        while (childpid != wait(&status))//si no es el proceso hijo
            if ((childpid == -1) && (errno != EINTR))           
                break; 
    exit(0); 
}