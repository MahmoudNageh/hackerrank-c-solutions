int maxElement(int n, int maxSum, int k) 
{
    
    int maxValue = 0;

    for (int val = 1; val <= maxSum; val++)
    {
        int sum = val;

        // Iterate j from K-1 to 0 and find the minimum value that could be placed at j 
        // That is the difference of val and distance between K and j and add value to sum.
        for (int j = k - 1; j >= 0; j--)
        {
            if ((val + j - k) > 0)
            {
                sum +=(val + j - k);
            }
         
            // The minimum value that could be placed at any index is 1
            else 
            {
                sum += 1;
            }
        }

        // Iterate j from K+1 to N-1
        for (int j = k + 1; j < n; j++) 
        {
            if ((val + k - j) > 0)
            {
                sum +=(val + k - j);
            }
            else
            {
                sum += 1;
            }
        }

        // If sum is less than or equal to maxSum then update maxValue with val, otherwise terminate the loop
        if (sum <= maxSum)
        {
            maxValue = val;
        }
        else
        {
            break;
        }
    }
    
    return maxValue;
}
