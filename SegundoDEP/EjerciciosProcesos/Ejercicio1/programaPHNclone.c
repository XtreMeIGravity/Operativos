#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/wait.h>

int hijo(void *arg);
int nieto(void *arg);
int main()
{
    printf("Soy proceso Padre y mi PID es %d\n",getpid());
    /////////////INICIO PROCESO HIJO/////////////
    int pid1;
    void *pchild_stack = malloc(1024 * 1024);
    if ( pchild_stack == NULL ) {
        printf("Error:No hay suficiente espacio en memoria.\n");
        exit(EXIT_FAILURE);
    }
    if((pid1 = clone(hijo, pchild_stack + (1024 * 1024), NULL, NULL)) == 0){
        //SE CREO CON EXITO//
    }
    wait(NULL);
    free(pchild_stack);//libera la memoria
    /////////////FIN PROCESO HIJO/////////////
    return 0;
}

int hijo(void *arg){
    printf("Soy proceso hijo y mi PID es %d hijo de %d\n",getpid(),getppid());
    /////////////INICIO PROCESO NIETO/////////////
    int pid2;
    void *pchild_stack = malloc(1024 * 1024);
    if ( pchild_stack == NULL ) {
        printf("Error:No hay suficiente espacio en memoria.\n");
        exit(EXIT_FAILURE);
    }
    if((pid2 = clone(nieto, pchild_stack + (1024 * 1024), NULL, NULL)) == 0){
        //SE CREO CON EXITO//
    }
    wait(NULL);
    free(pchild_stack);//libera la memoria
    /////////////FIN PROCESO NIETO/////////////
   return 0;
}
int nieto(void *arg){
   printf("Soy proceso nieto y mi PID es %d hijo de %d\n",getpid(),getppid());
   return 0;
}