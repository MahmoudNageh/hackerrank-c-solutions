#define MOD 1000000007

long temp_arr[1000000];
long occ_arr[1000000];
    
int renameFile(char* newName,char* oldName)
{
    long new_lenght = strlen(newName);
    long old_length = strlen(oldName);
    

    for (long z = 0; z < old_length + 1; z++)
    {
        temp_arr[z] = 1;
    }

    for (long i = 1; i < new_lenght + 1; i++) 
    {
        for (long z = 0; z < old_length + 1; z++) 
        {
            occ_arr[z] = 0;
        }

        for (long j = i; j < old_length + 1 ; j++)
        {
            occ_arr[j] = occ_arr[j - 1];

            if (newName[i - 1] == oldName[j - 1])
                occ_arr[j] += temp_arr[j - 1];

        }

        for (long z = 0; z < old_length + 1; z++) 
        {
            temp_arr[z] = occ_arr[z];
        }
        
    }
 
    return occ_arr[old_length] % MOD;
}
