
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/wait.h>

int hijo(char *arg);
int nieto(char *arg);
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
    // HIJO Y NIETO IZQ//
    if((pid1 = clone(hijo, pchild_stack + (1024 * 1024), NULL, "IZQ")) == 0){
        //SE CREO CON EXITO//
    }
    // HIJO Y NIETO DER//
    if((pid2 = clone(hijo, pchild_stack + (1024 * 1024), NULL, "DER")) == 0){
        //SE CREO CON EXITO//
    }
    //finalizacion//
    wait(NULL);
    wait(NULL);
    free(pchild_stack);//libera la memoria
    /////////////FIN PROCESO HIJO/////////////
    return 0;
}

int hijo(char *arg){
    printf("Soy proceso hijo %s y mi PID es %d hijo de %d\n",arg ,getpid(),getppid());
    /////////////INICIO PROCESO NIETO/////////////
    int pid2;
    void *pchild_stack = malloc(1024 * 1024);
    if ( pchild_stack == NULL ) {
        printf("Error:No hay suficiente espacio en memoria.\n");
        exit(EXIT_FAILURE);
    }
    if((pid2 = clone(nieto, pchild_stack + (1024 * 1024), NULL, arg)) == 0){
        //SE CREO CON EXITO//
    }else{
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    free(pchild_stack);//libera la memoria
    /////////////FIN PROCESO NIETO/////////////
   return 0;
}
int nieto(char *arg){
   printf("Soy proceso nieto %s y mi PID es %d hijo de %d\n",arg,getpid(),getppid());
   return 0;
}
