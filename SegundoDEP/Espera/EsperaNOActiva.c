/*INSTITUTO POLITÉCNICO NACIONAL
         ESCUELA SUPERIOR DE CÓMPUTO
           SISTEMAS OPERATIVOS
              SEMESTRE 2020-2
                GRUPO: 2CV8
        ALUMNO:
          -- LÓPEZ HERNÁNDEZ DAVID

Compilar: gcc EsperaNOActiva.c -o EsperaNOActiva.out -lpthread -lrt */

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

#define TAM_MEM 2
int *Memoria;
#define stop1 100
#define stop2 300
#define stop3 500
#define stopCons1 250 
#define stopCons2 500

int CreaLigaMemoria( void );
void DestruyeMemoria( int id_Memoria , int *buffer );
sem_t * CrearSemaforo(  char *name , int val );

int main(){
    int pid,pid2,pid3,pid4,id;
    char *name1 = "consumidor";
    char *name2 = "productor";
    char *name3 = "consumidor2";
    char *name4 = "productor2";
    sem_t *semaforoConsumidor , *semaforoProductor,*semaforoConsumidor2 , *semaforoProductor2;

    semaforoConsumidor = CrearSemaforo( name1 , 0 );
    semaforoProductor = CrearSemaforo( name2 , 1 );
    semaforoConsumidor2 = CrearSemaforo( name3 , 0 );
    semaforoProductor2 = CrearSemaforo( name4 , 1 );
    
    if( (pid = fork()) == 0 ){
        id = CreaLigaMemoria();
        int i,j;
        i=j=0;
        while(!(i==stop1 && j==stop1)){
            if(sem_wait( semaforoProductor ) >= 0 && i < stop1){
                Memoria[0] = i;
                printf("Prod1: %d\n",i);
                i++;
                sem_post( semaforoConsumidor );
            }
            if(sem_wait( semaforoProductor2 ) >= 0 && j <stop1){
                Memoria[1] = j;
                printf("\t\t\tProd1: %d\n",j);
                j++;
                sem_post( semaforoConsumidor2 );
            }
        }
        sem_unlink( name1 );
        sem_unlink( name2 );
        sem_unlink( name3 );
        sem_unlink( name4 );
        _exit(0);
    }else if ( (pid2=fork()) == 0 ){
        id = CreaLigaMemoria();
        int i,j;
        i=j=stop1;
        while(!(i==stop2 && j==stop2)){
            if(sem_wait( semaforoProductor ) >= 0 && i < stop2){
                Memoria[0] = i;
                printf("Prod2: %d\n",i);
                i++;
                sem_post( semaforoConsumidor );
            }
            if(sem_wait( semaforoProductor2 ) >= 0 && j <stop2){
                Memoria[1] = j;
                printf("\t\t\tProd2: %d\n",j);
                j++;
                sem_post( semaforoConsumidor2 );
            }
        }
        sem_unlink( name1 );
        sem_unlink( name2 );
        sem_unlink( name3 );
        sem_unlink( name4 );
        _exit(0);
    }else if ( (pid3=fork()) == 0 ){
        id = CreaLigaMemoria();
        int i,j;
        i=j=stop2;
        while(!(i==stop3 && j==stop3)){
            if(sem_wait( semaforoProductor ) >= 0 && i < stop3){
                Memoria[0] = i;
                printf("Prod2: %d\n",i);
                i++;
                sem_post( semaforoConsumidor );
            }
            if(sem_wait( semaforoProductor2 ) >= 0 && j <stop3){
                Memoria[1] = j;
                printf("\t\t\tProd2: %d\n",j);
                j++;
                sem_post( semaforoConsumidor2 );
            }
        }
        sem_unlink( name1 );
        sem_unlink( name2 );
        sem_unlink( name3 );
        sem_unlink( name4 );
        _exit(0);
    }else if ( (pid4=fork()) == 0 ){
        id = CreaLigaMemoria();
        int i,j;
        i=j=0;
        printf(">>>>>>>>%d             %d<<<<<<\n",i,j);
        while(!(i==stopCons1 && j==stopCons1)){
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
        sem_unlink( name1 );
        sem_unlink( name2 );
        sem_unlink( name3 );
        sem_unlink( name4 );
        _exit(0);
    }else{
        id = CreaLigaMemoria();
        int i,j;
        i=j=stopCons1;
        printf(">>>>>>>>%d             %d<<<<<<\n",i,j);
        while(!(i==stopCons2 && j==stopCons2)){
            if(sem_wait( semaforoConsumidor ) >= 0 && i < stopCons2){
                printf("Cons2: %d\n",Memoria[0]);
                i++;
                sem_post( semaforoProductor );
            }
            if(sem_wait( semaforoConsumidor2 ) >= 0 && j < stopCons2){
                printf("\t\t\tCons2: %d\n",Memoria[1]);
                j++;
                sem_post( semaforoProductor2 );
            }
        }
        printf(">>>>>>>>%d             %d<<<<<<\n",i,j);

        wait(NULL);
        wait(NULL);
        wait(NULL);
        wait(NULL);
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
        sem_close( semaforoConsumidor2 );
        sem_destroy( semaforoConsumidor2 );
    }
    return 0;
}

int CreaLigaMemoria( void ){
    int key2,shmid;
    key2 = ftok("/bin/ls",3);
    //Verifica si existe la zona de memoria
    if( ( shmid = shmget( key2 , sizeof( int ) * TAM_MEM , IPC_CREAT|IPC_EXCL|0666) ) == -1 ){
        // Si existe obtiene la memoria 
        if( ( shmid = shmget( key2 , sizeof( int ) * TAM_MEM , 0 ) ) == -1 ){
            perror("shmget \n");
            exit(1);
        }
        else
            printf("Se ligo a la memoria con id: %d\n",shmid);
    }else
        printf("Creo la memoria con id: %d\n",shmid);
    //Se liga a la zona de memoria compartida
    if( ( Memoria = (int*)shmat( shmid , (int*) 0 , 0 ) ) == (void*)-1 ){
        perror("shmat \n");
        exit(1);
    }

    return shmid; //Descriptos de la memoria
}

void DestruyeMemoria( int id_Memoria , int *buffer ){
    if( id_Memoria != 0 || id_Memoria != -1 ){ //Valida si ya se destruyo
        shmdt( buffer );                       //Quita la liga hacia la memoria
        shmctl( id_Memoria , IPC_RMID , (struct shmid_ds *) NULL ); //Destruye la zona de memoria
        printf("Se destruyo la memoria\n");
    }else{
        shmdt( buffer );
        printf("Se desligo la memoria\n");
    }
}

sem_t * CrearSemaforo( char *name , int val){
    sem_t *mut;
    if( ( mut = sem_open( name , O_CREAT | O_EXCL , 0666 , val ) ) == SEM_FAILED ){
        if( ( mut = sem_open( name , 0 ) ) == SEM_FAILED )
            printf("Error al abrir el semaforo\n");
        else
            printf("Ligado al semaforo correctamente %p\n", mut);
    }else{
        printf("Semaforo creado: %p\n",mut);
        sem_init( mut , 1 , val );
    }
    return mut;
}