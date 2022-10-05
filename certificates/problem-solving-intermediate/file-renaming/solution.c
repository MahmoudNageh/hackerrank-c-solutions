#define MOD 1000000007

int renameFile(char* newName,char* oldName)
{
    int new_lenght = strlen(newName);
    int old_length = strlen(oldName);

    int temp_arr[10000];
    int occ_arr[10000];

    for (int z = 0; z < old_length + 1; z++)
    {
        temp_arr[z] = 1;
    }

    for (int i = 1; i < new_lenght + 1; i++) 
    {
        for (int z = 0; z < old_length + 1; z++) 
        {
            occ_arr[z] = 0;
        }

        for (int j = i; j < old_length + 1 ; j++)
        {
            occ_arr[j] = occ_arr[j - 1];

            if (newName[i - 1] == oldName[j - 1])
                occ_arr[j] += temp_arr[j - 1];

        }

        for (int z = 0; z < old_length + 1; z++) 
        {
            temp_arr[z] = occ_arr[z];
        }
        
    }
 
    return occ_arr[old_length] % MOD;
}
