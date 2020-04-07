#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h> 
int main (){   
    if ( fork() == 0 ){ /*RETORNA -1 en caso de error,                  
                        si es el proceso hijo retorna 0 y el                  
                        proceso padre retorna el PID (Process identifier) 
                        asignado al proceso hijo 
                         */        
        /*
            Se crea un proceso diferente , con su PID correspondiente, 
            al crear dos programas a uno le corresponde el PID del hijo
            y a otro el del padre , entonces , como primero se ejecuta el padre
            al llegar a la instruciion wait este se detiene hasta que el proceso hijo termine
            Por eso en ejecucion observaremos que se imprime de al reves a comparacion del ejemplo anterior.
        */
        printf ("Este es el hijo\n");   //Al retornar un 0 sabe que es proceso hijo
    }else{
        wait(NULL);  //el proceso padre entra en pausa hasta que se le notifique el su proceso hijo termino
        printf ("Este es el padre\n"); 
    }   
    exit(EXIT_SUCCESS); 
    return 0;
}
