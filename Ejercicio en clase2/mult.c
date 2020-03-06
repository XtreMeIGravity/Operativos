#include <stdio.h>

int main(){
    int var1=0,var2=0;
    for (var1 = 1; var1 <= 10; var1++)
    {
        var2=0;
        for (var2 = 1; var2 <= 10; var2++)
        {
            printf("%d",var1);
            printf("x");
            printf("%d",var2);
            printf("=");
            printf("%d\n",var1*var2);
        }
        
    }
    
    return 0;
}