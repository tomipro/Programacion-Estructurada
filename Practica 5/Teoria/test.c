#include <stdio.h>

struct sNodo {
    int valor;
    struct sNodo* sig; /* pointer to next node */
};

typedef struct sNodo* tNodo;

void insertarEnListaPrimero(tNodo*, int);

int main(void){
    unsigned int n, c;

    tNodo lista = NULL;
    insertarEnListaPrimero(&lista, 114);

    return 0;
}

void insertarEnListaPrimero(tNodo* nodo, int valor){
    tNodo aux;

    if (*nodo == NULL){
        *nodo = (tNodo) malloc(sizeof(struct sNodo));
        (*nodo)->valor = valor;
        (*nodo)->sig = NULL;
    }
    else {
        
    }
}