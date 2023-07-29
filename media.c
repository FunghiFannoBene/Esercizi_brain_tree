#include <stdlib.h>

double windows(int* arr, int size)
{
    int i; 
    i = 0;
    int sum;
    sum = 0;
    double result;
    while(i < size)
        sum += arr[i++];
    return(result = (double)sum/size);
}

double* media_mobile(int arr[], int window, int size)
{
    double *media = (double *)malloc(sizeof(double) * (size-(window-1)));
    double tmp;
    int *point;
    point = arr;
    int i;
    i=0;
    while(i+(window-1)<size)
    {
        tmp = windows(point, window);
        media[i] = tmp;
        i++;
        *point++;
    }
    return(media);
}

int main()
{
    int arr[6] = {1,2,2,3,2,4};
    double*media;
    int w = 2;
    int n = 6;
    int i;
    i=0;
    if(w == 1)
    {
        media = (double*)malloc(n * sizeof(double));
        while (i < n) 
        {
            media[i] = (double)arr[i];
            i++;
        }
    }
    else
      media = media_mobile(arr, w , n);
    while(i < n-(w-1))
    {
      printf("%lf\n", media[i++]);
    }
    free(media);
    media = NULL;
    return(0);
}
