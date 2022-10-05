#define MAX(a,b) ((a) > (b) ? (a) : (b))

int cmp(const void* a, const void* b) 
{
    return *(const int*) a - *(const int*) b;
}

int maxH, maxV, boundry;

long maxArea(int w, int h, int* horizontalCuts, int horizontalCutsSize, int* verticalCuts, int verticalCutsSize) 
{
	if ( boundry == 0 )
	{
		maxH = MAX(horizontalCuts[0], h - horizontalCuts[horizontalCutsSize - 1]);

		for (int i = 1; i < horizontalCutsSize; i++) 
		{
        		maxH = MAX(maxH, horizontalCuts[i] - horizontalCuts[i-1]);
    		}
    	}
	else if(boundry == 1)
	{
    		maxV = MAX(verticalCuts[0], w - verticalCuts[verticalCutsSize - 1]);
	
    		for (int i = 1; i < verticalCutsSize; i++) 
		{
        		maxV = MAX(maxV, verticalCuts[i] - verticalCuts[i-1]);
    		}
	}
    	return maxH * maxV;
}

long* getMaxArea(int w, int h, int isVertical_count, bool* isVertical,int distance_count, int* distance, int* result_count)
{
	maxH = h;
	maxV = w;

	*result_count = isVertical_count;

	long* result = (long*) malloc(isVertical_count * sizeof(long));

	// Boundry counters
	int horizontalCutsSize = 0;
	int verticalCutsSize   = 0;

	int* horizontalCuts = (int*) malloc(isVertical_count * sizeof(int));
	int* verticalCuts   = (int*) malloc(isVertical_count,  * sizeof(int));

	for (int i = 0; i < isVertical_count, ; i++)
	{
		// horizontal Boundry
		if (isVertical[i] == 0)
		{
			boundry = 0;
			horizontalCuts[horizontalCutsSize] = h - distance[i];
			horizontalCutsSize++;
			qsort(horizontalCuts, horizontalCutsSize, sizeof(int), cmp);
		}

		// Vertical Boundry
		else if (isVertical[i] == 1)
		{
			boundry =1;
			verticalCuts[verticalCutsSize] = distance[i];
			verticalCutsSize++;
			qsort(verticalCuts, verticalCutsSize, sizeof(int), cmp);
		}
		
		result[i] = maxArea(w, h, horizontalCuts, horizontalCutsSize, verticalCuts, verticalCutsSize);
	}
	
	free(horizontalCuts);
	free(verticalCuts);

	return result;
}
