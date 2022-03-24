#include <stdio.h>
#define LIM 100

int main(void){
    int i = 0;
    char texto[LIM] = {0};
    char car;
    printf("Ingrese texto: ");
    char term = '\n';

    if (i < LIM-1){
        fflush(stdin);
        car = getchar();
    }
    while (car != term && i<LIM-1){
        texto[i] = car;
        i++;

        if (i < LIM-1){
            car = getchar();
        }
        texto[i] = '\n';
    }
    // i = 0;
    
    for (i=0; texto[i]!='\0';i++){
        printf("%c", texto[i]);
    }

    return 0;
}

// int main(void){
//     char cadena[100];
//     int i = 0;

//     while (cadena[i] != '\n'){
//         fflush(stdin);
//         getchar();
//         // scanf("%c", &cadena[i]);
//         i++;
//     }

//     i = 0;
//     while (cadena[i] != '\n'){
//         printf("%c", cadena[i]);
//         i++;
//     }


//     return 0;

// }