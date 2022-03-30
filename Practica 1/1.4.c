#include <stdio.h>
#define TAM 10
#define TERM1 0

void cargarArr(int arr[TAM]);
void imprimirArr(int arr[TAM]);
int largoArr(int arr[TAM]);
void invertirArr(int arr[TAM]);
void ordenarArr(int arr[TAM]);

int main(void){
    int arr1[TAM] = {0};
    int largo;
    int arr2[TAM] = {0};

    cargarArr(arr1);
    printf("El array es: ");
    invertirArr(arr1);
    imprimirArr(arr1);
    printf("\n");
    cargarArr(arr2);
    ordenarArr(arr2);
    printf("\nArray 2 ordenado: ");
    imprimirArr(arr2);
    return 0;
}

void cargarArr(int arr[TAM]){
    int i = 0;
    int aux;
    printf("Ingrese numeros enteros, (0 para terminar): ");

    if (i < TAM-1){
        scanf("%d", &aux);
    }
    while (aux != TERM1 && i<TAM-1){
        arr[i] = aux;
        i++;
        if (i<TAM-1){
            scanf("%d", &aux);
        }
    }
}

void imprimirArr(int arr[TAM]){
    int i;

    for (i=0; arr[i]!=TERM1 && i<TAM; i++){
        printf("%d, ", arr[i]);
    }
}

int largoArr(int arr[TAM]){
    int i = 0;

    for (i = 0; i<TAM-1 && arr[i] != TERM1; i++);
    return i-1;
    
}

void invertirArr(int arr[TAM]){
    int aux;
    int i = 0;
    int largo1 = largoArr(arr);
    int largo2 = largoArr(arr)/2;

    while (i <= largo2 && arr[i] != 0){
        aux=arr[i];
        arr[i] = arr[largo1];
        arr[largo1] = aux;
        i++;
        largo1--;

    }
}

void ordenarArr(int arr[TAM]){
    int i, j, temp;
    int largo = largoArr(arr);
    for (i = 0; i < largo; i++){
        for (j = 0; j < largo - i - 1; j++){
            if (arr[i] < arr[j]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
