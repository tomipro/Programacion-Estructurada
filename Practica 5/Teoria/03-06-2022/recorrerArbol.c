/*

// SIN TERMINAR

#include <stdio.h>
#include <stdlib.h>

typedef struct sNodo
{
    unsigned int valor;
    struct sNodo *sig;
} * tNodo;

typedef struct sNodoBin
{
    int valor;
    struct sNodoBin *izq;
    struct sNodoBin *der;

} * tNodoBin;


void buscarYBorrarEnArbol(tNodoBin *arbol, int valor){
    if (*arbol) != NULL{
        if (valor < (*arbol) -> valor){
            buscarYBorrarEnArbol(& (*arbol) -> valor);
        }
        else if (valor > (*arbol) -> der, valor){
            buscarYBorrarEnArbol(& (*arbol) -> valor);
        }
    }
}

void eliminarArbol(tNodoBin *arbol){
    if ((*arbol) != NULL){
        eliminarArbol(&((*arbol)->izq)); //recorrido A IZQ
        eliminarArbol(&((*arbol)->der)); // recorricdo A DERECHA
        free(*arbol); // proceso
        *arbol = NULL; //proceso
    }
}

int sumar(tNodoBin arbol, int min, int max);

*/