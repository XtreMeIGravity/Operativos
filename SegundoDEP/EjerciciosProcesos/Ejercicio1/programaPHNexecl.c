#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
int main() {

    printf("Soy proceso Padre y mi PID es %d\n",getpid());
    char *args[]={"./hijo",NULL}; 
    execl(args[0],args[0],args[1]); 
      
    return 0; 
} 