void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int sortedSum(int a_count, int* a) 
{
    long long ans = 0, M = 1e9 + 7;
  
    for(int i = 0; i < a_count; i++) 
    {
         int j = i;
         while(j > 0 && a[j - 1] > a[j]) 
         {
             swap(&a[j], &a[j-1]);
             j--;
         }
         for(int j = 0; j <= i; j++)
         {
             ans = (ans + a[j] * 1ll * (j + 1)) % M;
         }
         ans %= M;
    }
    return ans;
}
