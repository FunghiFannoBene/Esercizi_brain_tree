#include <stdlib.h>
#include <stdio.h>
void findIndexes(int* v, int n, int size)
{
    int i = 0;
    int c = 1;

    while (i < size)
    {
        c = i + 1;
        while (c < size)
        {
            if ((v[i] + v[c]) == n)
            {
                printf("k: %d\n", i);
				printf("w: %d\n", c);
				exit(0);
            }
            c++;
        }
        i++;
    }
}
int main()
{
    int arr[9] = {1,2,2,4,5,6,7,8,37};
    int n;
    int size;
    n = 4; 
    size = 9;
    findIndexes(arr, n, size);
}
