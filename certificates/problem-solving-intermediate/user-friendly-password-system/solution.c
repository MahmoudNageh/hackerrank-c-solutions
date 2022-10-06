#define p 131
#define M 1000000007

unsigned long long hashing( char* password, int psw_len)
{
    unsigned long long hash_value = 0;
    
    
    for(long i = 0; i < psw_len; i++)
    {
        hash_value = hash_value + ((long)password[i] * pow(p,psw_len-(i+1)));
    }
    
    return (hash_value % M); 

}

int* authEvents(int events_rows, int events_columns, char*** events, int* result_count) 
{
    unsigned long long authorize = 0;
    unsigned long long hash_value = 0;
    unsigned long long hash_value_2 = 0;
    unsigned long long hash_value_3 = 0;
    
    unsigned long long x = 0;
    unsigned long long sum =0;
    
    long res_count = 0;
    long psw_len =0;
    
    char * password     = (char*) malloc(15 * sizeof(char));
    char * password_2   = (char*) malloc(15 * sizeof(char));
    char * password_3   = (char*) malloc(15 * sizeof(char));
    int* result         = (int*) calloc(events_rows , sizeof(int));

    for(int i = 0; i < events_rows; i++)
    {
        if(events[i][0][0] == 's')
        {
            long j;
            
            for ( j = 0; events[i][1][j] != '\0' ; j++)
            {
                psw_len         = strlen(events[i][1]);
                password[j]     = events[i][1][j];
                password_2[j]   = events[i][1][j];
                password_3[j]   = events[i][1][j];
            }
        
            if(events[i][1][j] == '\0')
            {
                password[j] = '\0';
                password_2[j] = 'z';
                password_2[j+1] = '\0';
                password_3[j] = '0';
                password_3[j+1] = '\0';
            }
        }

        else if(events[i][0][0] == 'a')
        {
            authorize = 0;
            
            for ( long j = 0; events[i][1][j] != '\0'; j++)
            {
                authorize = authorize * 10;
                authorize += (long)events[i][1][j] - 48;
            }
            
            hash_value      = hashing(password, psw_len);
            hash_value_2    = hashing(password_2, psw_len+1);
            hash_value_3    = hashing(password_3, psw_len+1);
            
            if ( authorize == hash_value || (authorize >= hash_value_3 && authorize <= hash_value_2))
            {
                result[res_count] = 1;
                res_count++;
            }
            else
            {
                result[res_count] = 0;
                res_count++;
            }   
        }
        
    }
    
    *result_count = res_count;
    return result;

}
