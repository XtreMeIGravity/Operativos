/* INSTITUTO POLITÉCNICO NACIONAL
         ESCUELA SUPERIOR DE CÓMPUTO
           SISTEMAS OPERATIVOS
              SEMESTRE 2020-2
                GRUPO: 2CV8
        ALUMNO:
          -- LÓPEZ HERNÁNDEZ DAVID
*/

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
    while(1){
        if(i==stopCons1 && j==stopCons1){
            break;
        }
        if(sem_wait( semaforoConsumidor ) >= 0 && i < stopCons1){
            printf("Cons1: %d\n",Memoria[0]);
            i++;
            sem_post( semaforoProductor );
        }
        if(sem_wait( semaforoConsumidor2 ) >= 0 && j < stopCons1){
            printf("\t\t\tCons1: %d\n",Memoria[1]);
            j++;
            sem_post( semaforoProductor2 );
        }
    }
    printf(">>>>>>>>%d             %d<<<<<<\n",i,j);

    sem_post(finalizar1);
    return 0;   
}