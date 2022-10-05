

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    
    // This contains the number of books on each shelf. (used a calloc to initializes each block with a 0.)
    total_number_of_books=(int*)calloc(total_number_of_shelves , sizeof(int));
    
    // This is a 2D array contains the number of pages of a book on a shelf.
    total_number_of_pages=(int**)calloc(total_number_of_shelves , sizeof(int*));
    
    for(int i=0; i<total_number_of_shelves; i++)
    {
        total_number_of_pages[i]=(int*)malloc(sizeof(int));
    }
    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            int x, y;
            scanf("%d %d", &x, &y);
            
            // This will increament the number of books in the xth shelf.
            total_number_of_books[x]+=1;
            
            // This will reallocate the size of the x shelf to the number of books in it.
            // in other words this will change the length of the row (shelf) in the 2D array.
            total_number_of_pages[x]=realloc(total_number_of_pages[x], total_number_of_books[x] *sizeof(int));
            
            // This will put the number of pages y on the last book on the xth shelf.
            // the first argument will choose the shelf (total_number_of_pages[x])
            // the second argument will go to the last element on the shelf.
            *(total_number_of_pages[x]+ total_number_of_books[x]-1)=y;
            
            
