int minOp ( *arr, thershold, divisor)
{
	arr_lenght = len(arr);

	qsort(arr, arr_length, sizeof(int), cmpfunc);

	int counter = 0;
	
	int max = 0;
	
	// kind of a hash table for the elements occurrence
	int *occ_arr = (int*) calloc( arr[arr_lengh -1], sizeof(int));

	
	for( int i = 0; i < arr_lenght; i++)
	{
		occ_arr[arr[i]]++;
		
		// check if the thershold is already met..
		if(occ_arr[arr[i]] == threshold)
		{
			return 0;
		}
	}

	while (1)
	{	
		arr[arr_length -1] = arr[arr_length -1] / 2;
		
		occ_arr[arr[arr_length-1]]++;

		counter++;

		if (occ_arr[arr[arr_length-1]] == threshold)
		{
			return counter;
		}
		
		else
		{
			qsort(arr, arr_length, sizeof(int), cmpfunc);
		}
	} 		
		
}
