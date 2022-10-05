#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int num[10]={0,0,0,0,0,0,0,0,0,0};

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    
    for(int i=0; i<strlen(s); i++)
    {
        switch (s[i])
        {
            case '0':
                num[0]+=1;
                break;
            
            case '1':
                num[1]+=1;
                break;
                
            case '2':
                num[2]+=1;
                break;
                
            case '3':
                num[3]+=1;
                break;
                
            case '4':
                num[4]+=1;
                break;
                
            case '5':
                num[5]+=1;
                break;
                
            case '6':
                num[6]+=1;
                break;
                
            case '7':
                num[7]+=1;
                break;
                
            case '8':
                num[8]+=1;
                break;
                
            case '9':
                num[9]+=1;
                break;
                
            default:
            break;
        }   
    }
    
        for(int i=0; i<=9; i++)
        {
        printf("%d ", num[i]);
        }
    return 0;
}
