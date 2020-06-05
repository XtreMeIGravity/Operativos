#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 

int main (){   
    if ( fork() == 0 ) /*RETORNA -1 en caso de error,
                        el proceso hijo retorna 0 y el 
                        proceso padre retorna el PID 
                        asignado al proceso hijo  */
        printf ("Este es el hijo\n");   //Al retornar un 0 sabe que es proceso hijo
    else       
        printf ("Este es el padre\n"); // Retorna el pid de el proceso hijo , por lo tanto
                                       // fue creado con exito
    exit(EXIT_SUCCESS); 
    return 0;
}