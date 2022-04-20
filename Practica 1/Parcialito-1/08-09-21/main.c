#include <stdio.h>
#define C 20
#define F 20
#define TERM_STR '\0'

FILE* abrirArchivo(char nomArch[50], char modo[]);
void cargarMat(FILE* fp, char mat[F][C]);
void imprimirMat(char mat[F][C]);
void clave(char mat[F][C], char claveMat[F]);

int main(void){
    FILE* fp;
    char mat[F][C] = {0};
    char claveMat[F] = {0};

    fp = abrirArchivo("codigo.txt", "r");
    cargarMat(fp, mat);
    fclose(fp);
    imprimirMat(mat);
    
    return 0;
}

FILE* abrirArchivo(char nomArch[50], char modo[]){
    return fopen(nomArch, modo);
}

void cargarMat(FILE* fp, char mat[F][C]){
    int f = 0, c = 0, leido;
    leido = fgetc(fp);

    while ((f < F - 1) && (leido != EOF) && (leido != '\n') && (leido != '\t') && (leido != ',')){
        c = 0;
        while ((c < C - 1) && (leido != EOF) && (leido != '\n') && (leido != '\t') && (leido != ',')){
            mat[f][c] = leido;
            leido = fgetc(fp);
            c++;
        }
        mat[f][c] = TERM_STR;
        f++;
        if (leido != EOF){
            leido = fgetc(fp);
        }
    }
    mat[f][0] = TERM_STR;
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

void clave(char mat[F][C], char claveMat[F]){
    int i = 0, j = 0;

    for (i = 0; i < F - 1 && mat[i][0] != TERM_STR; i++){
        for (j = 0; j < C - 1 && mat[i][j] != TERM_STR; j++){
            claveMat[i] = mat[i][j];
        }
    }
    clave[i] = TERM_STR;
}