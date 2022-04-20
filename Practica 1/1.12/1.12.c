#include <stdio.h>
#define F 20
#define C 20
#define TERM_DATO -999

FILE* abrirArch(char nomArch[50], char modo[]);
void cargarMat(FILE* arch, int mat[F][C]);
void imprimirMat(int mat[F][C]);

int main(void){
    FILE *fp;
    int mat[F][C] = {0};

    fp = abrirArch("puntos.txt", "r");
    cargarMat(fp, mat);
    fclose(fp);
    imprimirMat(mat);

    return 0;
}

FILE* abrirArch(char nomArch[50], char modo[]){
    return fopen(nomArch, modo);
}

void cargarMat(FILE* arch, int mat[F][C]){
    int a, b, c, i = 0;

    fscanf(arch, "%d,%d,%d,%d,%d,%d,%d,%d\n", &mat[i][0], &mat[i][1], &mat[i][2], &mat[i][3], &mat[i][4], &mat[i][5], &mat[i][6], &mat[i][7]);
    mat[i][8] = TERM_DATO;
    i = 1;
    while (!feof(arch) && i < F - 1){
        fscanf(arch, "%d,%d,%d,%d,%d,%d,%d,%d\n", &mat[i][0], &mat[i][1], &mat[i][2], &mat[i][3], &mat[i][4], &mat[i][5], &mat[i][6], &mat[i][7]);
        mat[i][8] = TERM_DATO;
        i++;
    }
    mat[i][0] = TERM_DATO;
}

void imprimirMat(int mat[F][C]){
    int j = 0, i = 0;

    for (i = 0; mat[i][0] != TERM_DATO && i < F; i++){
        for (j = 0; mat[i][j] != TERM_DATO && j < C; j++){
            if (j == 7 && mat[i][j] > 0){
                printf("%+6d", mat[i][j]);
            }
            else {
                printf("%6d", mat[i][j]);
            }
        }
        printf("\n");
    }
}