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
    finalizar2 = CrearSemaforo( name6    , 1 );
    id = CreaLigaMemoria();
    int i,j;
    i=j=stop2;
    int value1,value2;
    while(1){
        if(i==stop3 && j==stop3){
            break;
        }
        sem_getvalue(semaforoProductor, &value1);
        sem_getvalue(semaforoProductor2, &value2);
        if(value1 == 1 && i < stop3){
            sem_wait( semaforoProductor );
            Memoria[0] = i;
            printf("Prod2: %d\n",i);
            i++;
            sem_post( semaforoConsumidor );
        }else if(value2 == 1 && j <stop3){
            sem_wait( semaforoProductor2 );
            Memoria[1] = j;
            printf("\t\t\tProd2: %d\n",j);
            j++;
            sem_post( semaforoConsumidor2 );
        }
    }
    return 0;   
}