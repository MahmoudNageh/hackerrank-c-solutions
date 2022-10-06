 int cmp(const void* a, const void* b) 
{
    return *(const int*) a - *(const int*) b;
}

int  dp[200001][2] = { 0 };

int minOperations(int arr_count, int* arr, int threshold, int d) 
{
    //sorting
    
    qsort(arr, arr_count, sizeof(int), cmp);
    
    int minO = INT_MAX;

    for (int i = 0; i < arr_count; i++)
    {
        int steps = 0;
        
        while (1)
        {
            int x = arr[i];
            dp[x][0] += 1;
            dp[x][1] += steps;
            
            if (dp[x][0] >= threshold)
                minO = ( minO <= dp[x][1] )? minO : dp[x][1];
                
            if (x == 0)
                break;
                
            arr[i] /= d;
            steps += 1;
        }
    }
    return minO;
}
