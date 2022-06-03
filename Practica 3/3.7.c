#include <stdio.h>
#include <stdlib.h>

char *cargarStrDin();

int main(void)
{
    char *str = cargarStrDin();
    printf("Cargado: %s\n", str);

    return 0;
}


char *cargarStrDin(){
    int i = 0;
    char letra;
    char *arr = NULL;

    arr = (char *) malloc(sizeof(char));
    if (arr == NULL){
        return NULL;
    }
    letra = getchar();
    while (letra != '\n'){
        *(arr + i) = letra;
        i++;
        arr=(char *) realloc(arr, (i+1) *sizeof(char));
        if (arr == NULL){
            return NULL;
        }
        letra = getchar();
    }
    arr[i] = '\0';
    printf("\n");

    return arr;
}
