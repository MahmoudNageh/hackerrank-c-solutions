int taskOfPairing(int freq_size, int* freq)
{
    int pairsCnt = 0;
    
    int prevRemainder = 0;
    
    for (int i = 0; i < freq_size; i++)
    {
        if (freq[i] == 0)
        {
            prevRemainder = 0;
            continue;
        }
        
        freq[i] += prevRemainder;
        pairsCnt += freq[i] / 2;
        prevRemainder = freq[i] % 2;
    }
    
    return pairsCnt;
}
