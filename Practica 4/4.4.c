#include <stdio.h>
#define TAM 5

void invertir(int *, unsigned int);
void imprimirArr(int arr[TAM]);
void invertir2(int *arr, int indiceIzq, int indiceDer);

int main(void){
    int arr[TAM] = {0, 1, 2, 3, 4};
    printf("\nArreglo original: ");
    imprimirArr(arr);
    printf("\nArreglo reversa: ");
    invertir(arr, TAM);
    imprimirArr(arr);
    printf("\nArreglo reversa de la reversa: ");
    invertir2(arr, 0, TAM - 1);
    imprimirArr(arr);
    printf("\n");
    
    return 0;
}

void invertir(int *v, unsigned int t){
    int aux;

    if (t > 1){
        aux = v[t - 1];
        v[t - 1] = v[0];
        v[0] = aux;
        invertir(v + 1, t - 2);
    }
}

void imprimirArr(int arr[TAM]){
    printf("{");
    for (int i = 0; i < TAM; ++i){
        printf(" %d ", arr[i]);
    }
    printf("}\n");
}

void invertir2(int *arr, int indiceIzq, int indiceDer){
    int aux;

    if (indiceIzq <= indiceDer){
        aux = arr[indiceIzq];
        arr[indiceIzq] = arr[indiceDer];
        arr[indiceDer] = aux;
        invertir2(arr, indiceIzq + 1, indiceDer - 1);
    }
}