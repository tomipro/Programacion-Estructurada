#include <stdio.h>
#define TAM 10
#define TERM 0

void cargarArrPNR(int arr[TAM]);
int estaEnArr(int arr[TAM], int num);
int esPos(int num);
void imprimirArr(int arr[TAM]);

int main(void){
    int arr[TAM] = {0};
    cargarArrPNR(arr);
    printf("El array es:\t");
    imprimirArr(arr); //imprime el array arr

    return 0;
}

int estaEnArr(int arr[TAM], int num){
    int i;
    int res = 0;

    for (i = 0; arr[i] != TERM && i < TAM; i++){
        if (arr[i] == num){
            res = 1;
        }
    }
    return res; //retorna 1 si ya esta en array, 0 si no esta
}

int esPos(int num){
    int res = 1;
    if (num < 0){
        res = 0;
    }
    return res; //retorna 1 si es >= 0, 0 si es negativo
}

void cargarArrPNR(int arr[TAM]){
    int aux, i = 0;

    printf("Ingrese numero (0 para terminar)");

    if (i < TAM - 1){
        scanf("%d", &aux);
    }

    while (aux != TERM && i < TAM-1){
        if (esPos(aux) == 1 && estaEnArr(arr, aux) == 0){
            arr[i] = aux;
            i++;
            scanf("%d", &aux);
        }
        while (esPos(aux) == 0 || estaEnArr(arr, aux) == 1 && aux != TERM && i < TAM-1){
            printf("Error, numero no valido. ");
            scanf("%d", &aux);
        }
    }
}

void imprimirArr(int arr[TAM]){
    int i;

    for (i = 0; arr[i] != 0 && i < TAM-1; i++){
        printf("%d", arr[i]);
    }
}