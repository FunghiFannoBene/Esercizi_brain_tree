#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checksum(int massimo, int*hash, int size, int stop)
{
    int i;
    i=0;
    int res = 0;

    while(i < size && i + massimo <= stop)
    {
        if(hash[i] > 0 && (i + massimo) == stop)
        {
            if(hash[i] == -1)
              hash[i] = 0;
            return hash[i];
        }
        i++;
    }
    return 0;
}

void findIndexes(int *v,int n, int size)
{
    int *hash = malloc(sizeof(int) * n);
    memset(hash, 0, n * sizeof(int));
    int i;
    i=0;
    int k;
    int w;
    int flag;
    flag = 0;
    w=0;
    k = 0;
    while(i<size)
    {
        if(v[i] > (n-1))
        {
            i++;
            continue;
        }
        else
        {
        if(v[i] == 1)
          hash[v[i]] = -1;
        else
          hash[v[i]] = i;
        }
        i++;
    }
    i=0;
    int tmp = n-1;
    while(tmp != 0)
    {
        while(tmp && !hash[tmp] || flag)
        {
            tmp--;
            if(flag)
              flag = 0;
        }
        k = checksum(tmp, hash, n, n);
        if(k != 0)
        {
            w = hash[tmp];
            if(w == k)
            {
              k=0;
              w=0;
              flag = 1;
              continue;
            }
            break;
        }
        flag = 1;
    }
    free(hash);
    if(k == 0)
    {
        printf("nessun risultato possibile");
    }
    else
        printf("index k: %d index: w:%d", k, w);
}

int main()
{
    int arr[9] = {1,2,4,5,6,7,8,99,234};
    int n;
    int size;
    n = 13; 
    size = 9;
    findIndexes(arr, n, size);
}
