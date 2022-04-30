#include <stdio.h>

#define C 20
#define F 20
#define TERM_STR '\0'

int cargarMat(char mat[F][C]);
void imprimirMat(char mat[F][C]);
// void matClave(char mat[F][C], char mat[F]);

int main(void){
    int res = 0;
    char mat[F][C] = {0};
    char matClave[F] = {0};
    res = cargarMat(mat);

    if (res){
        cargarMat(mat);
        printf("Matriz cargada:\n");
        imprimirMat(mat);
    }

    return 0;
}

int cargarMat(char mat[F][C]){
    int f = 0, c = 0, res = 0, leido;

    FILE* arch = fopen("codigo.txt", "r");
    if (arch == NULL){
        printf("ERROR. No se pudo cargar archivo.\n");
        res = 1;
    }
    else {
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
    return res;
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