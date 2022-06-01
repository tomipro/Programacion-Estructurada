#include <stdio.h>

void fun(int *pun1, int *pun2);

int main(void){
    int num1, num2;
    int *pun1 = &num1;
    int *pun2 = &num2;
    printf("Ingrese primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese segundo numero: ");
    scanf("%d", &num2);

    printf("Inicio:\nDireccion: %d: %d\n%d: %d\n\n", &num1, num1, &num2, num2);
    fun(pun1, pun2);
    printf("Fin:\nDireccion: %d: %d\n%d: %d\n", &num1, num1, &num2, num2);
    
    return 0;
}

void fun(int *pun1, int *pun2){
    int aux;

    aux = *pun1;
    *pun1 = *pun2;
    *pun2 = aux;
}