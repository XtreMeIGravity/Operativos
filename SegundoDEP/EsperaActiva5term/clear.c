/*
Compilar: gcc EsperaActiva.c -lpthread -lrt */

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
#include "aux.h"

int main(){
    int id;
    char *name1 = "consumidor";
    char *name2 = "productor";
    char *name3 = "consumidor2";
    char *name4 = "productor2";
    char *name5 = "finalizar1";
    char *name6 = "finalizar2";
    sem_t *semaforoConsumidor , *semaforoProductor,*semaforoConsumidor2 , *semaforoProductor2,
    *finalizar1,*finalizar2;;
    semaforoConsumidor = CrearSemaforo( name1 , 0 );
    semaforoProductor = CrearSemaforo( name2 , 1 );
    semaforoConsumidor2 = CrearSemaforo( name3 , 0 );
    semaforoProductor2 = CrearSemaforo( name4 , 1 );
    finalizar1 = CrearSemaforo( name5 , 0 );
    finalizar2 = CrearSemaforo( name6 , 1 );
    id = CreaLigaMemoria();    
    sem_unlink( name1 );
    sem_unlink( name2 );
    sem_unlink( name3 );
    sem_unlink( name4 );
    sem_unlink( name5 );
    sem_unlink( name6 );

    DestruyeMemoria( id , Memoria );
    sem_unlink( name1 );
    sem_unlink( name2 );
    sem_unlink( name3 );
    sem_unlink( name4 );
    sem_close( semaforoProductor );
    sem_destroy( semaforoProductor );
    sem_close( semaforoConsumidor );
    sem_destroy( semaforoConsumidor );
    sem_close( semaforoProductor2 );
    sem_destroy( semaforoProductor2 );

    sem_close( finalizar2 );
    sem_destroy( finalizar2 );
    sem_close( finalizar1 );
    sem_destroy( finalizar1 );


    return 0;   
}