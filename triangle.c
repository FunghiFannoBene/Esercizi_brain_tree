#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void triangle(int n)
{
    if (n <= 0) 
	{
        return;
    }
    
    static int spaces = 0;
    char *stringa = malloc(n + spaces + 1);

    memset(stringa, ' ', spaces);
    memset(stringa + spaces, '*', n);
    stringa[n + spaces] = '\0';

    printf("%s\n", stringa);
    free(stringa);

    spaces++;
    triangle(n - 2);
}

int main()
{
    triangle(7);
    return 0;
}
