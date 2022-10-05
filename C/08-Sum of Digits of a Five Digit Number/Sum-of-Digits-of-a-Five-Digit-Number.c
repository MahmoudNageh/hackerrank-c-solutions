#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    int sum=0;
    scanf("%d", &n);
    
    /* for a generic algorithm you would make a while loop
     * and the condition will be until the number is null,
     * but in this case it says it will only be a 5 digit num.
     */
  
    for(int i=0; i<=5; i++)
    {
        sum=sum + n%10;
        n=n/10;
    }
  
    printf("%d", sum);
    return 0;
}
