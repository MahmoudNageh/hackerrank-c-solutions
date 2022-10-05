#include <stdio.h>

int max_of_four(int a, int b, int c, int d)
{
    int AwB, CwD, res;
    
    AwB = a > b ? a : b;
    CwD = c > d ? c : d;
    res = AwB > CwD ? AwB : CwD;
    
    return res;
}


int main() 
{
    int a, b, c, d;
  
    scanf("%d %d %d %d", &a, &b, &c, &d);
  
    int ans = max_of_four(a, b, c, d);
  
    printf("%d", ans);
    
    return 0;
}
