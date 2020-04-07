
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/wait.h>

int hijoDER(void *arg);
int hijoIZQ(void *arg);
int main()
{
    printf("Soy proceso Padre y mi PID es %d\n",getpid());
    /////////////INICIO PROCESO HIJO/////////////
    int pid1,pid2;
    void *pchild_stack = malloc(1024 * 1024);
    if ( pchild_stack == NULL ) {
        printf("Error:No hay suficiente espacio en memoria.\n");
        exit(EXIT_FAILURE);
    }
    ////////////////////////////////HIJO1////////////////////////////////
    if((pid1 = clone(hijoIZQ, pchild_stack + (1024 * 1024), NULL, NULL)) == 0){
        printf("Proceso hijo creado con exito");
    }
    ////////////////////////////////HIJO2////////////////////////////////
    if((pid2 = clone(hijoDER, pchild_stack + (1024 * 1024), NULL, NULL)) == 0){
        printf("Proceso hijo creado con exito");
    }
    //Finliza
    wait(NULL);
    wait(NULL);
    free(pchild_stack);//libera la memoria
    /////////////FIN PROCESO HIJO/////////////
    return 0;
}

int hijoIZQ(void *arg){
    printf("Soy proceso hijo izquierdo y mi PID es %d hijo de %d\n",getpid(),getppid());
   return 0;
}

int hijoDER(void *arg){
    printf("Soy proceso hijo derecho y mi PID es %d hijo de %d\n",getpid(),getppid());
   return 0;
}
