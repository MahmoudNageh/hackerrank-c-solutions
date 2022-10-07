#define  P          (131)
#define  MOD        (1000000007)


int setPassword(char* password)
{
	long res = 0;
	
	for (int i = 0; password[i]; i++)
	{
		res *= P;
		res %= MOD;
		res += password[i];
		res %= MOD;
	}
	
	return res;
}


int authorize(long correctHash, long inputHash)
{
	if (correctHash == inputHash)
		return 1;
	
	correctHash *= P;
	correctHash %= MOD;
	
	// try adding digits
	for (int i = '0'; i <= '9'; i++)
	{
		if ((correctHash + i) % MOD == inputHash)
			return 1;
	}
	
	// try adding lower characters
	for (int i = 'a'; i <= 'z'; i++)
	{
		if ((correctHash + i) % MOD == inputHash)
			return 1;
	}
	
	// try adding upper characters
	for (int i = 'A'; i <= 'Z'; i++)
	{
		if ((correctHash + i) % MOD == inputHash)
			return 1;
	}
	
	return 0;
}


int *authEvents(int events_rows, int events_columns, char ***events, int *result_count)
{
	int* res = malloc(events_rows * sizeof(int));
	int  resIdx = 0;
	int  currHash;
	
	for (int i = 0; i < events_rows; i++)
	{
		switch (events[i][0][0])
		{
			case 's':
				currHash = setPassword(events[i][1]);
			break;
			
			case 'a':
				res[resIdx] = authorize(currHash, atoi(events[i][1]));
				resIdx++;
			break;
		}
	}
	
	*result_count = resIdx;
	return res;
}
