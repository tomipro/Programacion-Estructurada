#include <stdio.h>
#include <stdlib.h>

#define L 10
#define TERM_DATO -999

typedef struct Coordenadas{
    int x;
    int y;
} Coordenadas;

void cargarArr(Coordenadas puntos[], char nomArch[50]);
int distMin(Coordenadas puntos[], int arr[L]);

int main(void){
    Coordenadas arr[L];

    cargarArr(arr, "puntos.csv");
    
    return 0;
}


void cargarArr(Coordenadas puntos[], char nomArch[50])
{
    FILE* f = fopen(nomArch, "r");
    int i = 0;
    for (int i = 0; i < L; ++i)
    {
        Coordenadas p;
        fscanf(f, "%d,%d,", &p.x, &p.y);
        puntos[i] = p;
        // printf("[%3.d]: (%d, %d)\n", i+1, p.x,p.y);
    }
}

int distMin(Coordenadas puntos[], int arr[L]){
    int min, i = 0;

    
}