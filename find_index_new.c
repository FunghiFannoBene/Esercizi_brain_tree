#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void findIndexes(int *v,int n, int size)
{
    int *hash = malloc(sizeof(int) * n);
    memset(hash, 0, n * sizeof(int));
    int i = 0;
    int tmp = n-1;
    while(i<size)
    {
        if(v[i] < (n-1))
        {
          if(v[i] == 1)
            hash[v[i]] = -1;
          else
            hash[v[i]] = i;
        }
        i++;
    }
    while(tmp > 0)
    {
        while(tmp && !hash[tmp])
            tmp--;
        if(tmp && hash[n-tmp] && hash[n-tmp] != hash[tmp])
        {
          if(hash[n-tmp] ==-1)
            hash[n-tmp] = 0;
            printf("Index k: %d Index: w: %d \n", hash[n-tmp], hash[tmp]);
            exit(0);
        }
        tmp--;
    }
    free(hash);
    printf("Nessun risultato possibile\n");
}

int main()
{
    int arr[9] = {2,4,2,4,5,7,7,8,37};
    int n;
    int size;
    n = 15; 
    size = 9;
    findIndexes(arr, n, size);
}
