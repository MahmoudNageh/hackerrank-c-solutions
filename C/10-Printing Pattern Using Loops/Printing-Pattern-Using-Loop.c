#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int n;
    int max;
    
    scanf("%d", &n);
  
    // the loops are (2*n-1) iterations 
  	for (int row = -n + 1; row < n; row++)
    {
        for (int col = -n + 1; col < n; col++)
        {
            max = abs(row) > abs(col) ? abs(row) : abs(col);
            printf("%d ", max + 1);
        }
        printf("\n");
    }

    return 0;
}
