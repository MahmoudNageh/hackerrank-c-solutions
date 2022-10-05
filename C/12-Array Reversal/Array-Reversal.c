#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr,*arrrev, i;
  
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
  
    for(i = 0; i < num; i++)
    {
        scanf("%d", arr + i);
    }

    arrrev = (int*) malloc(num * sizeof(int));
  
     for(i = 0; i < num; i++) 
     {
        arrrev[i]=arr[num-1-i];
    }
    
     for(i = 0; i < num; i++) 
     {
        arr[i]=arrrev[i];
        printf("%d ", arr[i]);
    } 
    
    free(arr);
    free(arrrev);
    return 0;
}
