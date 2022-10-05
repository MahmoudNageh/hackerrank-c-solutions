#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	char *s;
    s = malloc(1024 * sizeof(char));
    
	scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    
    //This prints each character on it's own and prints \n instead of spaces
    for(int i=0; i<strlen(s); i++)
    {
        if (s[i] == ' ')
            printf("\n");

        else 
            printf("%c",s[i]);
    }
    return 0;
}
