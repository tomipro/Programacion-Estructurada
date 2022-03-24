#include <stdio.h>
#define TAM 100

void cargarArr(char txt[TAM]);
void imprimirArr(char txt[TAM]);

int main(void){
    char txt[TAM]={0};

    cargarArr(txt);
    imprimirArr(txt);

    return 0;
}

void cargarArr(char txt[TAM]){
    int i = 0;
    char aux;
    char term = '\n';
    char cambio1 = ' ';
    char cambio2 = ' ';

    printf("Ingrese texto: ");

    if (i < TAM-1){
        fflush(stdin);
        aux = getchar();
    }

    while (aux != term && i < TAM-1){
        txt[i] = aux;
        i++;
        if (i<TAM-1){
            aux = getchar();
        }
        txt[i] = '\n';  
    }
    printf("\nIngrese caracter a reemplazar: ");
    cambio1 = getchar();
    fflush(stdin);
    printf("\nIngrese caracter de reemplazo: ");
    cambio2 = getchar();

    for (i=0; i<TAM-1; i++){
        if (txt[i] == cambio1){
            txt[i] = cambio2;
        }
    }
    
}

void imprimirArr(char txt[TAM]){
    printf("\nResultado: %s\n",txt);
}
