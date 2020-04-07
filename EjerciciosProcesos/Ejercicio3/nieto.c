#include <stdio.h>
void main() { 
     printf("Soy proceso nieto y mi PID es %d hijo de %d\n",getpid(),getppid());
} 