#include <stdio.h>

typedef struct
{
    int a;
    int b;
    int c;
} t_tres;

void ordenar(t_tres *tres);
// void sort(int n, int *ptr);
// void imprimirArr(int n, int arr[]);

int main(void)
{
    t_tres n = {2, 1, 5};
    // int largo = 9;
    // int arr[] = {4, 6, 9, 3, 12, 4, 7, 1, 6};
    printf("%d %d %d\n", n.a, n.b, n.c);
    ordenar(&n);
    printf("%d %d %d\n", n.a, n.b, n.c);
    // printf("\n");
    // imprimirArr(largo, arr);
    // sort(largo, arr);
    // imprimirArr(largo, arr);
    // printf("\n");

    return 0;
}

void ordenar(t_tres *tres){
    int i, j, aux;
    int *valores[3] = {&tres->a, &tres->b, &tres->c};

    for (i = 0; i < 2; i++){
        for (j = i + 1; j < 3; j++){
            if (*valores[j] < *valores[i]){
                aux = *valores[i];
                *valores[i] = *valores[j];
                *valores[j] = aux;
            }
        }
    }
}

/*
void sort(int n, int *ptr){
    int i, j, aux;

    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            if (*(ptr + j) > *(ptr + i)){
                aux = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = aux;
            }
        }
    }
}

void imprimirArr(int n, int arr[]){
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }   
}
*/