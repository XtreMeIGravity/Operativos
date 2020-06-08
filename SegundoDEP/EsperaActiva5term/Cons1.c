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
    int i,j;
    i=j=0;


    sem_wait(finalizar2);
    printf(">>>>>>>>%d             %d<<<<<<\n",i,j);
    int value1,value2;
    while(1){
        if(i==stopCons1 && j==stopCons1){
            break;
        }
        sem_getvalue(semaforoConsumidor, &value1);
        sem_getvalue(semaforoConsumidor2, &value2);
        if(value1 == 1 && i < stopCons1){
            sem_wait( semaforoConsumidor );
            printf("Cons1: %d\n",Memoria[0]);
            i++;
            sem_post( semaforoProductor );
        }else if(value2 == 1 && j < stopCons1){
            sem_wait( semaforoConsumidor2 );
            printf("\t\t\tCons1: %d\n",Memoria[1]);
            j++;
            sem_post( semaforoProductor2 );
        }
    }
    printf(">>>>>>>>%d             %d<<<<<<\n",i,j);

    sem_post(finalizar1);


    sem_unlink( name1 );
    sem_unlink( name2 );
    sem_unlink( name3 );
    sem_unlink( name4 );
    sem_unlink( name5 );
    sem_unlink( name6 );


    return 0;   
}