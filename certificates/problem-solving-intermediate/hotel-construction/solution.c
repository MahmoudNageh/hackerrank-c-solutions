#define  MAX_CITIES_CNT    (50)


void initDistance(int distance[MAX_CITIES_CNT][MAX_CITIES_CNT], int src, int des, int val, int citiesCnt, char isThereRoad[MAX_CITIES_CNT][MAX_CITIES_CNT])
{
    distance[src][des] = val;
    
    for (int nextDes = 0; nextDes < citiesCnt; nextDes++)
    {
        if (isThereRoad[des][nextDes] && distance[src][nextDes] == -1)
        {
            initDistance(distance, src, nextDes, val + 1, citiesCnt, isThereRoad);
        }
    }
}


int numberOfWays(int roads_rows, int roads_columns, int** roads) 
{
    int citiesCnt = roads_rows + 1;
    
    /*
     * isThereRoad[src][des] stores either 0 or 1:
     *   - 0: if there's no direct road from src city to des city
     *   - 1: if there's a  direct road from src city to des city
     */
    char isThereRoad[MAX_CITIES_CNT][MAX_CITIES_CNT] = {0};
    
    for (int i = 0; i < roads_rows; i++)
    {
        int city1 = roads[i][0] - 1;
        int city2 = roads[i][1] - 1;
        
        isThereRoad[city1][city2] = 1;
        isThereRoad[city2][city1] = 1;
    }
    
    
    /*
     * distance[src][des] stores distance between src city to des city 
     */
    int distance[MAX_CITIES_CNT][MAX_CITIES_CNT];
    
    // set all to -1 (uninitialized)
    for (int src = 0; src < citiesCnt; src++)
    {
        for (int des = 0; des < citiesCnt; des++)
        {
            distance[src][des] = -1;
        }
    }
    
    
    // initialize distances
    for (int src = 0; src < citiesCnt; src++)
    {
        // ditance from src city to itself = 0
        initDistance(distance, src, src, 0, citiesCnt, isThereRoad);
    }
    
    
    // get 3 cities with equal distances between each two
    int cnt = 0;
    
    for (int city1 = 0; city1 < citiesCnt; city1++)
    {
        for (int city2 = city1 + 1; city2 < citiesCnt; city2++)
        {
            for (int city3 = city2 + 1; city3 < citiesCnt; city3++)
            {
                if (distance[city1][city2] == distance[city1][city3] && distance[city1][city2] == distance[city2][city3])
                    cnt++;
            }
        }
    }
    
    return cnt;
}
