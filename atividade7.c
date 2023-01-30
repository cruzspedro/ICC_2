#include <stdio.h>

int main()
{
    int var1, var2;
    scanf("%d %d", &var1, &var2);
    int resultado = 0;
    if (var1 - var2 > 0)
    {
        for (int i = var2; i <= var1; i++)
        {
            resultado+=i;
        }
        
    }
    else
    {
         for (int i = var1; i <= var2; i++)
        {
            resultado+=i;
        }     
    }
    printf("%d", resultado);   
    return 0;
}