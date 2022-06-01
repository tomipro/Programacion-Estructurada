#include <stdio.h>
#define TERM 0

int maxR(int arr[], int indice, int max);
int minR(int arr[], int indice, int min);
int* maxDir(int arr[], int indice, int max);
void imprimirArr(int arr[], int t);

int main(void)
{
    int arr[] = {4, 6, 2, -3, 0, 9, 1};
    printf("\nArreglo original: ");
    imprimirArr(arr, 7);
    printf("\nEl maximo del arreglo es: ");
    printf("%d\n", maxR(arr, 6, arr[0]));
    printf("\nEl minimo del arreglo es: ");
    printf("%d\n\n", minR(arr, 6, arr[0]));
    printf("\n5b: %d\n", maxDir(arr, 6, arr[0]));

    return 0;
}

int maxR(int arr[], int indice, int max)
{
    if (indice == 0)
    {
        return max;
    }

    else
    {
        if (arr[indice] > max)
        {
            max = arr[indice];
        }
    }
    return maxR(arr, indice - 1, max);
}

int minR(int arr[], int indice, int min)
{
    if (indice == 0)
    {
        return min;
    }

    else
    {
        if (arr[indice] < min)
        {
            min = arr[indice];
        }
    }
    return minR(arr, indice - 1, min);
}

void imprimirArr(int arr[], int t)
{
    printf("{");
    for (int i = 0; i < t; ++i)
    {
        printf(" %d ", arr[i]);
    }
    printf("}\n");
}

int* maxDir(int arr[], int indice, int max)
{
    if (indice == 0)
    {
        return max;
    }

    else
    {
        if (arr[indice] > max)
        {
            max = arr[indice];
        }
    }
    return *maxDir(arr, indice - 1, max);
}

/*
if (*arr != TERM && *(arr+1) != 0)
 -- recursiva -- 
else
if (*arr == TERM)
    max = NULL
else
    max = arr;

return max

*/