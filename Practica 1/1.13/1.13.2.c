#include <stdio.h>

#define C 25
#define F 25
#define TERM_STR '\0'
#define TERM_DATO -999

FILE* abrirArch(char nomArch[50], char modo[]);
void cargarTitulo(FILE* arch, char mat[F][C]);
void cargarDatos(FILE* arch, int mat[F][C]);
void cargarItems(FILE* arch, char mat[F][C]);
void imprimirTitulo(char mat[F][C]);
void imprimirTabla(int matDatos[F][C], char matItems[F][C]);

int main(void){
    FILE *fp;
    char matTitulo[F][C] = {0};
    char matItems[F][C] = {0};
    int matDatos[F][C] = {0};

    fp = abrirArch("cabeceras.txt", "r");
    cargarTitulo(fp, matTitulo);
    fclose(fp);
    fp = abrirArch("items.txt", "r");
    cargarItems(fp, matItems);
    fclose(fp);
    fp = abrirArch("datos.txt", "r");
    cargarDatos(fp, matDatos);
    fclose(fp);

    imprimirTitulo(matTitulo);
    imprimirTabla(matDatos, matItems);

    return 0;
}

FILE* abrirArch(char nomArch[50], char modo[]){
    return fopen(nomArch, modo);
}

void cargarTitulo(FILE* arch, char mat[F][C]){
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

void cargarItems(FILE* arch, char mat[F][C]){
    int f = 0, c = 0, leido;
    leido = fgetc(arch);

    while ((c < C - 1) && (leido != EOF)){
        c = 0;
        while ((f < F - 1) && (leido != EOF) && (leido != '\n')){
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

void cargarDatos(FILE* arch, int mat[F][C]){
    int i = 0;

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

void imprimirTitulo(char mat[F][C]){
    int i = 0;
    printf("%-20s", mat[0]);
    for (i = 1; i < F - 1 && mat[i][0] != TERM_STR; i++){
        printf("%6s", mat[i]);
    }
    printf("\n---------------------------------------------------------------------\n");
}

void imprimirTabla(int matDatos[F][C], char matItems[F][C]){
    int i = 0, j = 0;

    for (i = 0; matItems[i][0] != TERM_STR && i < F - 1; i++){
        printf("%-20s", matItems[i]);
        for (j = 0; matDatos[i][j] != TERM_DATO && j < C - 1; j++){
            if (j == 7 && matDatos[i][j] > 0){
                printf("%+6d", matDatos[i][j]);
            }
            else {
                printf("%6d", matDatos[i][j]);
            }
        }
        printf("\n\n");
    }
    printf("\n");
}