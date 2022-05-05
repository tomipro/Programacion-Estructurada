#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define L 10
#define TERM_DATO -999

typedef struct Coordenadas{
    int x;
    int y;
} Coordenadas;

void cargarArr(Coordenadas puntos[], char nomArch[50]);
float dist(Coordenadas punto1,  Coordenadas punto2);
float minDistCons(Coordenadas puntos[]);
float minDistCualq(Coordenadas puntos[]);

int main(void){
    Coordenadas arr[L];

    cargarArr(arr, "puntos.csv");
    printf("Consecutivo: %.3f\n", minDistCons(arr));
    printf("Cualquiera: %.3f\n", minDistCualq(arr));
    
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
        printf("[%3.d]: (%d, %d)\n", i+1, p.x,p.y);   
    }
}

float dist(Coordenadas punto1,  Coordenadas punto2){
    return (sqrt(pow(punto1.x - punto2.x, 2) + pow(punto1.y - punto2.y, 2)));
}

float minDistCons(Coordenadas puntos[]){
    int i = 0;
    float minDist, distancia;

    for (i = 0; i < L; ++i){
        distancia = dist(puntos[i], puntos[i + 1]);
        if (i == 0 || (distancia < minDist)){
            minDist = distancia;
        }
    }
    return minDist;
}

float minDistCualq(Coordenadas puntos[]){
    int i = 0, j = 0;
    float minDist, distancia;

    for (i = 0; i < L-1; i++){
        for (j = i + 1; j < L; j++){
            distancia = dist(puntos[i], puntos[j]);
            if (distancia < minDist || i == 0){
                minDist = distancia;
            }
        }
    }
    return minDist;
}