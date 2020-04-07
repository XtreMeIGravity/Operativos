#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h>
#include <stdio.h>
 
int main(int argc, char *argv[])
{
    pid_t pid1, pid2, pid3, pid4;
    int status1, status2, status3, status4;
    if ( (pid1=fork()) == 0 ){ 
        if ( (pid2=fork()) == 0 ){ 
            printf("Soy proceso nieto IZQ y mi PID es %d hijo de %d\n",getpid(),getppid());
            _exit(1);
        }else{ 
            wait(&status2);//espera a que termine el proceso padre en este caso del nieto
            printf("Soy proceso hijo IZQ y mi PID es %d hijo de %d\n",getpid(),getppid());
            _exit(1);
        }
    }else{ 
        wait(&status2);//espera a que termine el proceso padre en este caso del hijo
        if ( (pid3=fork()) == 0 ){ 
            if ( (pid4=fork()) == 0 ){ 
                printf("Soy proceso nieto DER y mi PID es %d hijo de %d\n",getpid(),getppid());
                _exit(1);
            }else{ 
                wait(&status4);//espera a que termine el proceso padre en este caso del nieto
                printf("Soy proceso hijo DER y mi PID es %d hijo de %d\n",getpid(),getppid());
                _exit(1);
            }
        }else{ 
            wait(&status3);//espera a que termine el proceso padre en este caso del hijo
            printf("Soy proceso Padre y mi PID es %d\n",getpid());
        }
    }
 
    return 0;
}
