#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h>
#include <stdio.h>
 
int main(int argc, char *argv[])
{
    pid_t pid1, pid2;
    int status1, status2;
    if ( (pid1=fork()) == 0 ){ 
        if ( (pid2=fork()) == 0 ){ 
            printf("Soy el nieto (%d, hijo de %d)\n",getpid(), getppid());
        }else{ 
            wait(&status2);//espera a que termine el proceso padre en este caso del nieto
            printf("Soy el hijo (%d, hijo de %d)\n",getpid(), getppid());
        }
    }else{ 
        wait(&status1);//espera a que termine el proceso padre en este caso del hijo
        printf("Soy el padre %d \n", getpid()); /* PROCESO PRINCIPAL*/
    }
 
    return 0;
}
