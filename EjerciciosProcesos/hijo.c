#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 


int main() 
{ 
    printf("Soy proceso hijo y mi PID es %d hijo de %d\n",getpid(),getppid());
    char *args[]={"./nieto",NULL}; 
    execvp(args[0],args);
    return 0; 
} 