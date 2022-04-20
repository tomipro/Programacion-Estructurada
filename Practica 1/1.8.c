#include <stdio.h>
#define F 3
#define C 3

int ingresarMat(int f, int c);
void cargarMat(int arr[F][C]);
void imprimirMat(int arr[F][C]);
void transponer(int arr[F][C]);

int main(void){
    int arr[F][C] = {0};

    cargarMat(arr);
    imprimirMat(arr);
    printf("\n");
    transponer(arr);

    return 0;
}


void cargarMat(int arr[F][C]){
    int x, f = 0, c = 0;

    for (f = 0; f < F; f++){
        for (c = 0; c < C; c++){
            arr[f][c] = ingresarMat(f, c);
        }
    }
}

int ingresarMat(int f, int c){
    int x;

    printf("[%d][%d]: ", f, c);
    scanf("%d", &x);
    return x;
}

void imprimirMat(int arr[F][C]){
    int f = 0, c = 0;

    for (f = 0; f < F; f++){
        for (c = 0; c < C; c++){
            printf("%4d", arr[f][c]);
        }
        printf("\n");
    }
}

void transponer(int arr[F][C]){
    int f = 0, c = 0;

    for (f = 0; f < F; f++){
        printf("\n");
        for (c = 0; c < F; c++){
            printf("%4d", arr[c][f]);
        }
    }
}
