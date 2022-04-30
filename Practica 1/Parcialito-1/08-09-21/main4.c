#include <stdio.h>

#define C 20
#define F 20
#define TERM_STR '\0'

void cargarMat(char mat[F][C]);
void imprimirMat(char mat[F][C]);
void matClave(char mat[F][C], char matClave[F]);

int main(void){
    char mat[F][C] = {0};
    char matClave[F] = {0};

    cargarMat(mat);
    imprimirMat(mat);

    return 0;
}

void cargarMat(char mat[F][C]){
    int i = 0, j = 0, leido;
    
    FILE* fp = fopen("codigo.txt", "r");
    leido = fgetc(fp);
    while ((i < F - 1) && (leido != EOF)){
        j = 0;
        while ((j < C - 1) && (leido != EOF) && (leido != '\n')){
            mat[i][j] = leido;
            leido = fgetc(fp);
            j++;
        }
        mat[i][j] = TERM_STR;
        i++;
        if (leido != EOF){
            leido = fgetc(fp);
        }
    }
    mat[i][0] = TERM_STR;
    fclose(fp);
}

void imprimirMat(char mat[F][C]){
    int i = 0, j = 0;

    for (i = 0; i < F - 1 && mat[i][0] != TERM_STR; i++){
        for (j = 0; j < C - 1 && mat[i][j] != TERM_STR; j++){
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}