#include <stdio.h>
#include <stdlib.h>

typedef struct Coordenadas {
    int x;
    int y;
} Coordenadas;

void funcion(Coordenadas);

int main(void){
    Coordenadas coord = {0, 0};
    
    funcion(coord);

    return 0;
}

void funcion(Coordenadas coord){

    printf("Ingrese coordenada x: ");
    scanf("%d", &coord.x);
    printf("Ingrese coordenada y: ");
    scanf("%d", &coord.y);

    if (coord.x != 0 || coord.y != 0){
        if (abs(coord.x) > abs(coord.y)){
            printf("El punto mas lejos del origen es: %d\n", coord.x);
        }
        else {
            printf("El punto mas lejos del origen es: %d\n", coord.y);
        }
    }
    else {
        printf("Se ingreso (0, 0)\n");
    }

}