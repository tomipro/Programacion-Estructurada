#include <stdio.h>
#include <string.h>

#define CANT 25
#define F 30
#define C 30
#define TERM_DATO -999
#define TERM_STR '\0'

typedef struct Datos{
    char nombre[CANT];
    int ganados;
    int perdidos;
    int empatados;
    int golFavor;
    int golContra;
} Datos;

int cargarArrItemDato(Datos datos[F][C], char nomArchItem[], char nomArchDato[]);

int main(void){
    Datos datos[F];

    return 0;
}

int cargarArrItemDato(Datos datos[F][C], char nomArchItem[], char nomArchDato[]){
    int f = 0, c = 0, leido;
    FILE* fItems, *fDatos;
    fItems = fopen(nomArchItem, "r");
    fDatos = fopen(nomArchDato, "r");

    // FILE* archItem = fopen(nomArchItem, "r");
    // FILE* archDato = fopen(nomArchDato, "r");
    leido = fgetc(fItems);
    
    while ((f < F - 1) && (!feof(fItems)) && (!feof(fDatos))){
        c = 0;
        Datos datos;
        while ((c < C - 1) && (leido != EOF) && (leido != '\n')){
            datos.nombre[c] = leido;
            leido = fgetc(fItems);
            c++;
        }
        
    }
}