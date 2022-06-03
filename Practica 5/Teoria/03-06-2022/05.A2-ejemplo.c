#include <stdio.h>
#include <stdlib.h>

typedef struct sNodoBin
{
    int valor;
    struct sNodoBin *izq;
    struct sNodoBin *der;

} * tNodoBin;

void insertarEnArbol(tNodoBin *arbol, int valor);

int main(void)
{
    tNodoBin arbol = NULL;
    insertarEnArbol(&arbol, 7);
    insertarEnArbol(&arbol, 2);
    insertarEnArbol(&arbol, 10);
    insertarEnArbol(&arbol, 1);
    insertarEnArbol(&arbol, 4);
    insertarEnArbol(&arbol, 11);
    insertarEnArbol(&arbol, 3);
    insertarEnArbol(&arbol, 6);
    insertarEnArbol(&arbol, 5);

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