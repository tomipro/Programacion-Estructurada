#include <stdio.h>

#define C 20
#define F 20
#define TERM_STR '\0'

void cargarMat(char mat[F][C]);
void imprimirMat(char mat[F][C]);
void clave(char mat[F][C], char matClave[F]);

int main(void){
    char mat[F][C] = {0};
    char matClave[F] = {0};

    cargarMat(mat);
    imprimirMat(mat);
    clave(mat, matClave);
    imprimirMat(&matClave);
    
    return 0;
}

void cargarMat(char mat[F][C]){
    int f = 0, c = 0, leido;

    FILE* arch = fopen("codigo.txt", "r");
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

    printf("\n");
    for (i = 0; i < F - 1 && mat[i][0] != TERM_STR; i++){
        for (j = 0; j < C - 1 && mat[i][j] != TERM_STR; j++){
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void clave(char mat[F][C], char matClave[F]){
    int i = 0, j = 0;

    for (i = 0; i < F - 1 && mat[i][0] != TERM_STR; i++){
        matClave[i] = mat[i][i];
    }
    matClave[i] = TERM_STR;
}