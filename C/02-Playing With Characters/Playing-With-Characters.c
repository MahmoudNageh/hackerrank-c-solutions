#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char ch;
    char s[46]; //an array of 46 because the longest word in english is 45 char. long 
    char sen[100]; 
    
    scanf("%c", &ch );
    scanf("%s \n", &s );
    scanf("%[^\n]%*c", &sen );
    
    printf("%c \n", ch);
    printf("%s \n", s);
    printf("%s", sen);        
      
    return 0;
}
