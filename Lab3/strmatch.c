#include <stdlib.h>
#include <string.h>

int main()
{
    char text[] = "";
    int m = strlen(text);
    char str[] = "";
    int n = strlen(str);
    int ind = 0;
    int matches[100];
    
    for (int i = 0; i + n <= m; i++)
    {
        int match = 1;
        for (int j = 0; j < m; j++)
        {
            if (text[i + j] != str[j])
            {
                match = 0;
                break;
            }
        }
        if (match == 0)
        {
            break;
        }
        else if (match == 1)
        {
            matches[ind] = i;
            ind++;
        }
    }
}