#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F 30
#define C 30
#define TERM_STR '\0'

void cargarMat(char mat[F][C]);
void imprimirMat(char mat[F][C]);
void ordenarMat(char mat[F][C], char matOrdenada[F][C]);

int main(void)
{
    char mat[F][C] = {0};
    char matOrdenada[F][C] = {0};

    cargarMat(mat);
    imprimirMat(mat);
    //ordenarMat(mat, matOrdenada);
    //imprimirMat(matOrdenada);
    //printf("Hello world!\n");
    return 0;
}

void cargarMat(char mat[F][C]){
    int f = 0, c = 0, leido;
    FILE* arch = fopen("insumos.txt", "r");
    leido = fgetc(arch);

    while ((f < F - 1) && (leido != EOF)){
        c = 0;
        while ((c < C - 1) && (leido != EOF) && (leido != '\n')){
            mat[f][c] = leido;
            leido = fgetc(arch);
            c++;
        }
        mat[f][c] = TERM_STR;
        f++;
        if (leido != EOF){
            leido = fgetc(arch);
        }
    }
    mat[f][0] = TERM_STR;
    fclose(arch);
}

void imprimirMat(char mat[F][C]){
    int i = 0, j = 0;
    printf("Matriz:\n");
    for (i = 0; i < F - 1 && mat[i][0] != TERM_STR; i++){
        for (j = 0; j < C - 1 && mat[i][j] != TERM_STR; j++){
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}

/*
void ordenarMat(char mat[F][C], char matOrdenada[F][C]){
    int i = 0, j = 0;
    char temp[][];
    char matOrdenada[F][C] = {{'\0'}};

    for (i = 0; i < F - 1 && mat[i][0] != TERM_STR; i++){
        for (j = 0; j < C - 1 && mat[i][j] != TERM_STR; j++){
            if (strlen(mat[i][j]) < strlen(mat[i][j + 1])){
                mat[i][j] = temp[][];
                temp[][] = mat[i][j + 1];
                mat[i][j + 1] = matOrdenada;
            }
        }
    }
}
*/
