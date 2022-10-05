#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    int val;
    int sum=0;
  
    scanf("%d", &n);
    
    int*arr = (int*)malloc(n*sizeof(int));
    
    for(int i=0; i<n; i++)
    {
        scanf("%d", &val);
        sum+=val;
    }
  
    printf("%d",sum);
  
    free(arr);
    return 0;
}
