#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
int main() {

    printf("Soy proceso Padre y mi PID es %d\n",getpid());
    char *args[]={"./hijo","IZQ",NULL}; 
    execlp(args[0],args[0],args[1],args[2]); 
    args[1]="DER"; 
    execlp(args[0],args[0],args[1],args[2]); 
      
    return 0; 
} 