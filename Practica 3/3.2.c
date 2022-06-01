#include <stdio.h>
#define TAM 15

int* fun(int arr[TAM], int pos);


int main(void){
    int arr[TAM] = {1, 2, 3, 4, 5, 6, 8};
    int pos;
    printf("\nIngrese posicion: ");
    scanf("%d", &pos);

    int *puntero = fun(arr, pos);
    printf("\nDireccion de memoria en posicion %d: %p\n\n", pos, puntero);

    return 0;
}

int* fun(int arr[TAM], int pos){
    return arr + pos;
}

