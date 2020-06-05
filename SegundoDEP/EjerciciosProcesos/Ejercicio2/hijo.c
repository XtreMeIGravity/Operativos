#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 


int main(int argc, char *argv[])
{ 
    printf("Soy proceso hijo %s y mi PID es %d hijo de %d\n",argv[1],getpid(),getppid());
    return 0; 
} 