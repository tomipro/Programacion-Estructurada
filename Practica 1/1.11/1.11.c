#include <stdio.h>
#include <string.h>
#define F 25
#define C 25
#define N 25
#define LARGO 50
#define TERM_STR '\0'

FILE* abrirArch(char nomArch[LARGO], char modo[]);
void cargarArch(FILE* arch, char mat[F][C]);
void imprimirMat(char mat[F][C]);
void ordenarTexto(char mat[][N]);

int main(void){
    FILE *fp;
    char mat[F][C] = {0};

    fp = abrirArch("equipos.txt", "r");
    cargarArch(fp, mat);
    fclose(fp);
    imprimirMat(mat);
    ordenarTexto(mat);
    imprimirMat(mat);
    return 0;
}

FILE* abrirArch(char nomArch[LARGO], char modo[]){
    return fopen(nomArch, modo);
}

void cargarArch(FILE* arch, char mat[F][C]){
    int f = 0, c = 0, leido;
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
}

void imprimirMat(char mat[F][C]){
    int i = 0, j = 0;
    printf("\n");
    for (i = 0; i < F - 1 && mat[i][0] != TERM_STR; i++){
        printf("%s\n", mat[i]);
    }
    printf("\n");
}

void ordenarTexto(char mat[][N]){
    int i = 0, j = 0;
    char temp[50];
    

    for (i = 0; i < N - 1; i++){
        for (j = 1; j < N - 1; j++){
            if (strcmp(mat[i], mat[j]) > 0){
                strcpy(temp, mat[i]);
                strcpy(mat[i], mat[j]);
                strcpy(mat[j], temp);
            }
        }
    }
}