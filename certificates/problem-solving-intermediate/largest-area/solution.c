#define MAX(a,b) ((a) > (b) ? (a) : (b))

int cmp(const void* a, const void* b) 
{
    return *(const int*) a - *(const int*) b;
}

int maxArea(int w, int h, int* horizontalCuts, int horizontalCutsSize, int* verticalCuts, int verticalCutsSize) 
{
    	int maxH = MAX(horizontalCuts[0], h - horizontalCuts[horizontalCutsSize - 1]);
    	int maxV = MAX(verticalCuts[0], w - verticalCuts[verticalCutsSize - 1]);
	
    	for (int i = 1; i < horizontalCutsSize; i++) 
	{
        	maxH = MAX(maxH, horizontalCuts[i] - horizontalCuts[i-1]);
    	}

    	for (int i = 1; i < verticalCutsSize; i++) 
	{
        	maxV = MAX(maxV, verticalCuts[i] - verticalCuts[i-1]);
    	}

    	return maxH * maxV;
}

int* getMaxArea(int w, int h, int n, bool* isVertical, int* distance)
{
	int* result = (int*) malloc(n * sizeof(int));

	// Boundry counters
	int horizontalCutsSize = 0;
	int verticalCutsSize   = 0;

	int* horizontalCuts = (int*) malloc(n * sizeof(int));
	int* verticalCuts   = (int*) malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		// horizontal Boundry
		if (isVertical[i] == 0)
		{
			horizontalCuts[horizontalCutsSize] = h - distance[i];
			horizontalCutsSize++;
			qsort(horizontalCuts, horizontalCutsSize, sizeof(int), cmp);
		}

		// Vertical Boundry
		else if (isVertical[i] == 1)
		{
			verticalCuts[verticalCutsSize] = distance[i];
			verticalCutsSize++;
			qsort(verticalCuts, verticalCutsSize, sizeof(int), cmp);
		}
		
		result[i] = maxArea(w, h, *horizontalCuts, horizontalCutsSize, *verticalCuts, verticalCutsSize);
	}
	
	free(horizontalCuts);
	free(verticalCutsSize);

	return result;
}