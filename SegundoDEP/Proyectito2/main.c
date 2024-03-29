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
    
    int stopDatos=10000;
    int id_mem;
    stopProces(id_mem);
    id_mem = CreaLigaMemoria();
    Memoria[11]=Memoria[10]=0;
    /*printf("Memoria en 10 %d\n",Memoria[10]);*/

    int pid1,pid2,pid3,pid4,pid5,pid6,pid7;

            /* INCIALIZACION DE SEMAOFOROS*/
    /*zona 1*/
    sem_c1_z1 = CrearSemaforo( name_sem_c1_z1 , 0 );
    sem_p1_z1 = CrearSemaforo( name_sem_p1_z1 , 1 );
    sem_c2_z1 = CrearSemaforo( name_sem_c2_z1 , 0 );
    sem_p2_z1 = CrearSemaforo( name_sem_p2_z1 , 1 );
    sem_c3_z1 = CrearSemaforo( name_sem_c3_z1 , 0 );
    sem_p3_z1 = CrearSemaforo( name_sem_p3_z1 , 1 );
    sem_c4_z1 = CrearSemaforo( name_sem_c4_z1 , 0 );
    sem_p4_z1 = CrearSemaforo( name_sem_p4_z1 , 1 );
    sem_c5_z1 = CrearSemaforo( name_sem_c5_z1 , 0 );
    sem_p5_z1 = CrearSemaforo( name_sem_p5_z1 , 1 );
    /*zona 2*/
    sem_c1_z2 = CrearSemaforo( name_sem_c1_z2 , 0 );
    sem_p1_z2 = CrearSemaforo( name_sem_p1_z2 , 1 );
    sem_c2_z2 = CrearSemaforo( name_sem_c2_z2 , 0 );
    sem_p2_z2 = CrearSemaforo( name_sem_p2_z2 , 1 );
    sem_c3_z2 = CrearSemaforo( name_sem_c3_z2 , 0 );
    sem_p3_z2 = CrearSemaforo( name_sem_p3_z2 , 1 );
    sem_c4_z2 = CrearSemaforo( name_sem_c4_z2 , 0 );
    sem_p4_z2 = CrearSemaforo( name_sem_p4_z2 , 1 );
    sem_c5_z2 = CrearSemaforo( name_sem_c5_z2 , 0 );
    sem_p5_z2 = CrearSemaforo( name_sem_p5_z2 , 1 );
    /*semaforos files*/
    sem_f1 = CrearSemaforo( name_sem_f1 , 1 );
    sem_f2 = CrearSemaforo( name_sem_f2 , 1 );
    sem_f3 = CrearSemaforo( name_sem_f3 , 1 );
    sem_f4 = CrearSemaforo( name_sem_f4 , 1 );
    /*>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<*/
    //para prod1 y cons1
    sem_c1_b2 = CrearSemaforo( name_c1_b2 , 0 );
    sem_p1_b2 = CrearSemaforo( name_p1_b2 , 1 );
    sem_c1_b1 = CrearSemaforo( name_c1_b1 , 0 );
    sem_p1_b1 = CrearSemaforo( name_p1_b1 , 1 );
    //para prod2 y cons2
    sem_c2_b2 = CrearSemaforo( name_c2_b2 , 0 );
    sem_p2_b2 = CrearSemaforo( name_p2_b2 , 1 );
    sem_c2_b1 = CrearSemaforo( name_c2_b1 , 0 );
    sem_p2_b1 = CrearSemaforo( name_p2_b1 , 1 );
    //para prod3 y cons3
    sem_c3_b2 = CrearSemaforo( name_c3_b2 , 0 );
    sem_p3_b2 = CrearSemaforo( name_p3_b2 , 1 );
    sem_c3_b1 = CrearSemaforo( name_c3_b1 , 0 );
    sem_p3_b1 = CrearSemaforo( name_p3_b1 , 1 );
    //para prod4 y cons4
    sem_c4_b2 = CrearSemaforo( name_c4_b2 , 0 );
    sem_p4_b2 = CrearSemaforo( name_p4_b2 , 1 );
    sem_c4_b1 = CrearSemaforo( name_c4_b1 , 0 );
    sem_p4_b1 = CrearSemaforo( name_p4_b1 , 1 );
    
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