int maxElement(int n, int maxSum, int k) 
{
    if(n==1) return maxSum;
    int right =k;
    int left =k;
    int count = 1;
    int limitRight = n-1;
    
    while(n <= maxSum && (left > 0 || right < limitRight)){
        
        n+= right - left +1; if(left>0) left--; if(right < limitRight) right++; count++;}
        
        if(n<maxSum) count += (maxSum-n)/(right - left +1) +1;
        
        return count-1;
    
}
