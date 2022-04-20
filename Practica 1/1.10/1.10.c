#include <stdio.h>
#include <string.h>

#define LARGO 100
#define F 20
#define C 20
#define TERM_STR '\0'

FILE* abrirArch(char nombreArch[LARGO], char modo[]);
void cargarMatTexDeArch(FILE* arch, char mat[F][C]);
void imprimirMat(char mat[F][C]);

int main(void){
    FILE *fp;
    char mat[F][C] = {0};

    fp = abrirArch("equipos.txt", "r");
    cargarMatTexDeArch(fp, mat);
    fclose(fp);
    imprimirMat(mat);

    return 0;
}

FILE* abrirArch(char nombreArch[LARGO], char modo[]){
    return fopen(nombreArch, modo);
}

void cargarMatTexDeArch(FILE* arch, char mat[F][C]){
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
    for (i = 0; mat[i][0] != TERM_STR && i < F - 1; i++){
        printf("%s\n", mat[i]);
    }
    printf("\n");
}