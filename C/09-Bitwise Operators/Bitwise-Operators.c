#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calculate_the_maximum(int n, int k) 
{
    int maxand =0;
    int maxor  =0;
    int maxxor =0;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            maxand = ((i&j)>maxand)&&((i&j)<k) ? i&j : maxand;
            maxor  = ((i|j)>maxor) &&((i|j)<k) ? i|j : maxor;
            maxxor = ((i^j)>maxxor)&&((i^j)<k) ? i^j : maxxor;
        }
    }
  
    printf("%d\n%d\n%d", maxand, maxor, maxxor);
}

int main() 
{
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
