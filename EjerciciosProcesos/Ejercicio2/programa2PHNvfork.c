#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h>
#include <stdio.h>
 
int main(int argc, char *argv[])
{
    pid_t pid1,pid2;    
    int status1, status2;

    if ( (pid1=vfork()) == 0 ){ 
        printf("Soy proceso hijo izquierdo y mi PID es %d hijo de %d\n",getpid(),getppid());
        _exit(1);
    }else{
        if ( (pid2=vfork()) == 0 ){ 
            printf("Soy proceso hijo derecho y mi PID es %d hijo de %d\n",getpid(),getppid());
            _exit(1);
        }else{
            /* Esperamos al primer hijo */
            waitpid(pid1, &status1, 0);
            /* Esperamos al segundo hijo */
            waitpid(pid2, &status2, 0);
            printf("Soy proceso Padre y mi PID es %d\n",getpid());
        }
    }
    return 0;
}
