#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

long maxSubarrayValue(int n, int* arr) 
{
     long MAX = 0;

    //negate odd indexed elements
    for(int i=1;i<n;i+=2)
    {
        arr[i] = 0 - arr[i];
    }

    long maxSoFar = arr[0];
    long currMax = arr[0];
    long currMin = arr[0];
    long minSoFar = arr[0];

    for (int i = 1; i < n; i++)
    {
        currMax = max(arr[i] , currMax + arr[i]);
        maxSoFar = max(maxSoFar , currMax);
        if (currMin > 0)
            currMin = arr[i];
        else
            currMin += arr[i];

        minSoFar = min(minSoFar , currMin);
    }
    MAX =  abs(maxSoFar) > abs(minSoFar) ? abs(maxSoFar) : abs(minSoFar);

    return MAX * MAX;
}
