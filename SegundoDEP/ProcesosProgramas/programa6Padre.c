#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <errno.h> 
#include <stdio.h> 
#include <stdlib.h>

void main(int argc, char *argv[]) { 
    int pid; /*En pid almacenaremos el nº deidentificación de proceso devuelto por fork()*/ 
    pid=fork(); /*fork() crea un clon del proceso primitivo*/ 
    switch(pid) {   
        case -1: /*fork devuelve -1 en caso de error*/       
            printf("\nNo se puede crear proceso hijo");       
            exit(0); /* salimos al S.O.*/   
        break;
        case 0: /*el valor 0 es asignado al hijo, mientras que el */       
            /* proceso padre recibe el número de identificación del hijo*/       
            printf("\nnúmero de identificación del proceso HIJO%d",pid);
            execl("./programa6Hijo","programa6Hijo",NULL); /* ejecutamos el hijo */   
            /*n las llamadas al sistema exec..(), al contrario que wait(),
             el proceso hijo no  ejecutará  el  mismo  programa  que  el  
             proceso  padre,  sino  que  ejecuta  código almacenado en un
              fichero. Este fichero podrá ser un fichero binario ejecutable o un script.*/
        break;
        default:       
            printf("\n número de identificación del PADRE %d",pid);       
            sleep(1); /*E1 programa espera un segundo y termina */   
        break;
    }  
}