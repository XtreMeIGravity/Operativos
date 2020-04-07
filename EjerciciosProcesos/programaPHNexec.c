#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
int main() {

    printf("Soy proceso Padre y mi PID es %d\n",getpid());
    char *args[]={"./hijo",NULL}; 
    execvp(args[0],args); 
      
    return 0; 
} 