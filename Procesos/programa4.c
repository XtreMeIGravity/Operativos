#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h> 

void main (){   
    unsigned int status; 
    if ( fork() == 0 ){ /* ==0 en el hijo */   
        scanf("%d",&status);   //Escanea el valor de salida de del proceso hijo
        exit (status);          //termine el proceso hijo devolviendo en este un status, antes leido
    }else {/* !=0 en el padre */   
        wait (&status);   //pausa el proceso padre y manda el un apuntador de memoria para saber que nos va a retornar este proceso hijo
        printf ("hijo exit status = %d\n",status >> 8);// hace un corrimiento de 8 bits a la derecha   
    }   
    exit (0); //termina el proceso padre
}