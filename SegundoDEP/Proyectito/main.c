/*
Compilar: gcc main.c -o Proyectito.o -lpthread -lrt */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include "auxiliar.h"

int main(){
    LimpiaArchivos();
    
    int stopDatos=100000;
    int id_mem;
    
    stopProces(id_mem);
    int pid1,pid2,pid3,pid4,pid5,pid6,pid7;
    inicializaSemaforos();

    if( (pid1 = fork()) == 0 ){
        produce(1, id_mem, stopDatos);
    }else if( (pid2 = fork()) == 0 ){
        produce(2, id_mem, stopDatos);
    }else if( (pid3 = fork()) == 0 ){
        produce(3, id_mem, stopDatos);
    }else if( (pid4 = fork()) == 0 ){
        produce(4, id_mem, stopDatos);
    }else if( (pid5 = fork()) == 0 ){
        consume(id_mem,1);
    }else if( (pid6 = fork()) == 0 ){
        consume(id_mem,2);
    }else if( (pid7 = fork()) == 0 ){
        consume(id_mem,3);
    }else{
        consume(id_mem,4);
        wait(NULL);
        wait(NULL);
        wait(NULL);
        wait(NULL);
        wait(NULL);
        wait(NULL);
        wait(NULL);
        stopProces(id_mem);
        printf("Finalizado con exito\n");
    }
    return 0;
}