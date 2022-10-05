int and_res = 0;

int res = 0;

// loop through the array

for ( int i =0; i < arr_len-1; i++)
{
	for ( j = i+1; j < arr_len; j++
	{
		and_res = arr[i] & arr[j];
		
		// If the number is a power of two, then only 1 bit will be set in its binary representation
		// Zero is an exception 
		if ( and_res && (!(and_res & (and_res-1))) )
		{
			res += 1;
		}
	}
}
	     
return res;
