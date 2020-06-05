#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int creaRamaIzqDos(int h,int base);
int creaRamaDerTres(int h,int base);
int main(int argc, char *argv[])
{
    int n;
    do{
    printf("Introduce un numero mayor que 1\n");
    scanf("%d",&n);
    }while(n<2);
    if ( fork() == 0 ){ 
        printf("Soy proceso hijo izquierdo y mi PID es %d hijo de %d\n",getpid(),getppid());
        creaRamaIzqDos(n,1);
        _exit(1);
    }else{
        if ( fork() == 0 ){ 
            printf("Soy proceso hijo derecho y mi PID es %d hijo de %d\n",getpid(),getppid());
            creaRamaDerTres(n,1);
            _exit(1);
        }else{
            /* Esperamos al primer hijo */
            wait(NULL);
            /* Esperamos al segundo hijo */
            wait(NULL);
            printf("Soy proceso Padre y mi PID es %d\n",getpid());
        }
    }
    return 0;
}

int creaRamaIzqDos(int h,int base){
    for (int i = 0; i < 2; i++)
    {
        if(fork() == 0){
            printf("Mi Pid es %d el de mi padre %d\n",getpid(),getppid());
            base++;
            (base<h)?creaRamaIzqDos(h,base):printf("\0");
            exit(0);
        }
    }
    for (int i = 0; i < 5; i++){
        wait(NULL);
    }
    return 0;
}

int creaRamaDerTres(int h,int base){
    for (int i = 0; i < 3; i++)
    {
        if(fork() == 0){
            printf("Mi Pid es %d el de mi padre %d\n",getpid(),getppid());
            base++;
            (base<h)?creaRamaDerTres(h,base):printf("\0");
            exit(0);
        }
    }
    for (int i = 0; i < 5; i++){
        wait(NULL);
    }
    return 0;
}