#include <stdio.h>

int main(void){
    char arrC[10] = "Hola";
    char* parr = NULL;
    parr = arrC;

    printf("\n<  %p  >\n", arrC);
    printf("\n<  %p  >\n", parr);
    printf("\n");
    printf("%c\n", arrC[0]);
    printf(" %c <  %d  >\n", *(arrC + 1), (arrC + 0));
    printf("%c\n", *arrC); //para acceder variable correspondiente al puntero, se usa "*" ej: *nomVar
    printf("%c\n", arrC[1]);
    printf(" %c <  %d  >\n", *(arrC + 1), (arrC + 1));
    
    
    return 0;
}