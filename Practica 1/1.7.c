#include <stdio.h>
#define F 3
#define C 3

void cargarMat(int mat[F][C]);
void imprimirMat(int mat[F][C]);
float promMat(int mat[F][C]);

int main(void){
    int mat[F][C] = {0};
    float promedio;

    cargarMat(mat);
    printf("\n");
    imprimirMat(mat);
    float promedio = promMat(mat);
    printf("%.2f\n", promedio);

    return 0;
}

int ingresarIM(int f, int c){
	int x;
	printf("[%d][%d]: ", f, c);
	scanf("%d", &x); 
	return x;
}


void cargarMat(int mat[F][C]){
    int x, f = 0, c = 0;

    for (f = 0; f < F; f++){
        for (c = 0; c < C; c++){
            mat[f][c] = ingresarIM(f, c);
        }
    }

}

void imprimirMat(int mat[F][C]){
    int f = 0, c = 0;
    
    for (f = 0; f < F; f++){
        for (c = 0; c < C; c++){
            printf("%4d", mat[f][c]);
        }
        printf("\n");
    }
}

float promMat(int mat[F][C]){
    int i, j;
    int suma = 0;
    int tot = F * C;
 
    for (i = 0; i < F; i++){
        for (j = 0; j < C; j++){
            suma += mat[i][j];
        }
    }
    float prom = (float) suma / tot;
    return prom;
}
