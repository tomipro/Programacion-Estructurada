#include <stdio.h>
#include <string.h>

#define CANT 25
#define F 30
#define C 30
#define TERM_DATO -999
#define TERM_STR '\0'

typedef struct Datos{
    char nombre[CANT];
    int pts;
    int pj;
    int pg;
    int pe;
    int pp;
    int gf;
    int gc;
    int dif;
} Datos;

int cargarArrItemDato(Datos datos[F][C], char nomArchItem[], char nomArchDato[]);

void imprimir(Datos datos[]);

int main(void){
    Datos datos[F];
    cargarArrItemDato(datos, "items.txt", "datos.txt");

    return 0;
}

int cargarArrItemDato(Datos datos[F][C], char nomArchItem[], char nomArchDato[]){
    int f = 0, c = 0, leido;
    FILE* fItems, *fDatos;
    fItems = fopen(nomArchItem, "r");
    fDatos = fopen(nomArchDato, "r");
    if (fItems == NULL || fDatos == NULL){
        return -1;
    }
    // FILE* archItem = fopen(nomArchItem, "r");
    // FILE* archDato = fopen(nomArchDato, "r");
    leido = fgetc(fItems);
    f = 0;
    while ((f < F - 1) && (!feof(fItems)) && (!feof(fDatos))){
        Datos datos;
        fscanf(fDatos, "%d, %d, %d, %d, %d, %d, %d, %d\n", &datos.pts, &datos.pj, &datos.pg, &datos.pe, &datos.pp, &datos.gf, &datos.gc, &datos.dif);
        
        c = 0;
        while ((c < C - 1) && (leido != EOF) && (leido != '\n')){
            datos.nombre[c] = leido;
            leido = fgetc(fItems);
            c++;
        }
        datos.nombre[c] = TERM_STR;
        if (leido != EOF){
            leido = fgetc(fItems);
        }
    }
    fclose(fItems);
    fclose(fDatos);

    return 0;
}