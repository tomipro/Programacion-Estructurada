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

void insertarEnArbol(tNodoBin *arbol, int valor);

int main()
{
    tNodoBin arbol = NULL;
    printf("\n-------------------");
    insertarEnArbol(&arbol, 35);
    insertarEnArbol(&arbol, 45);
    insertarEnArbol(&arbol, 30);
    insertarEnArbol(&arbol, 20);
    insertarEnArbol(&arbol, 31);

    return 0;
}

void insertarEnArbol(tNodoBin *arbol, int valor)
{
    if (*arbol == NULL)
    {
        *arbol = (tNodoBin)malloc(sizeof(struct sNodoBin));
        (*arbol)->valor = valor;
        (*arbol)->izq = NULL;
        (*arbol)->der = NULL;
    }

    else
    {
        if (valor < (*arbol)->valor)
        {
            insertarEnArbol(&(*arbol)->izq, valor);
        }
        else
        {
            insertarEnArbol(&(*arbol)->der, valor);
        }
    }
}