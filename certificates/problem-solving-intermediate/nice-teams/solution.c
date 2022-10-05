int cmpfunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int maxPairs(int skillLevel_count, int* skillLevel, int minDiff) 
{
    qsort(skillLevel,skillLevel_count, sizeof(int), cmpfunc);
    int l = 0;
    int r = skillLevel_count / 2 + 1;
    while(r - l > 1)
    {
        int m = (l + r) / 2;
        bool good = true;
        for(int i = 0; i < m; i++)
            good &= (skillLevel[skillLevel_count - m + i] - skillLevel[i] >= minDiff);
        if(good)
            l = m;
        else
            r = m;
    }
    return l;
}
