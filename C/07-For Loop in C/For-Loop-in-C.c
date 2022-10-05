#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char *strings[] = {"one","two","three","four","five","six","seven","eight","nine"};

int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);

    for(int i=a; i<=b ;i++)
    {
        if (i<=9)
        {
            printf("%s\n", strings[i-1]);
        }
        else if (i>9 && (i%2)==0)
        {
            printf("even\n");
        }
        else if (i>9 && (i%2)!=0) 
        {
            printf("odd\n");
        }
    }
    return 0;
}

