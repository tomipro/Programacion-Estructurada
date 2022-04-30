#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define F 10
#define C 56


int cargarmatriz(char insumos[F][C], FILE *archivo);
int imprimirmatriz(char insumos[F][C]);
int ordenarmatriz(char insumos[F][C]);


int cargarmatriz(char insumos[F][C], FILE *archivo){
    int i,t;
    char l;
    for (i = 0; l != EOF; i++){
        l = fgetc(archivo);
        for (t = 0; l != '\n' && l != EOF; t++){
            insumos[i][t] = l;
            l = fgetc(archivo);
        }
        insumos[i][t] = '\0';
        //printf("%s %d\n", insumos[i], i);
    }
    insumos[i][0] = '\0';
    return 0;
}


int imprimirmatriz(char insumos[F][C]){
    for(int i = 0; insumos[i][0] != '\0'; i++){
        printf("%s\n", insumos[i]);
    }
    return 0;
}


int ordenarmatriz(char insumos[F][C]){
    char aux[C] = {'\0'};
    for (int i = 0; insumos[i][0] != '\0'; i++){
        for (int t = 0; insumos[t][0] != '\0'; t++){
            if (strlen(insumos[i]) > strlen(insumos[t])){
                strcpy(aux, insumos[i]);
                strcpy(insumos[i], insumos[t]);
                strcpy(insumos[t], aux);
            }
        }
    }
    return 0;
}


int main()
{
    FILE *archivo = fopen("insumos.txt", "r");
    char insumos[F][C] = {{'\0'}};
    cargarmatriz(insumos, archivo);
    printf("Matriz cargada: \n");
    imprimirmatriz(insumos);
    ordenarmatriz(insumos);
    printf("\nMatriz ordenada: \n");
    imprimirmatriz(insumos);
    return 0;
}
