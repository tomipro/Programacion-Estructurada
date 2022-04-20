#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define C 100

int cargarmatriz(int f, char matriz[f][C]);
int imprimirmatriz(int f, char matriz[f][C]);
int ordenarmatriz(int f, char matriz[f][C]);


int cargarmatriz(int f, char matriz[f][C]){
  char l = '\0';
  int i;
  fflush(stdin);
  for (int fila = 0; fila < f; fila++){
    printf("\nIngrese texto para fila %d: ", fila+1);
    l = getchar();
    for (i = 0; l != '\n'; i++){
      matriz[fila][i] = l;
      l = getchar();
    }
    matriz[fila][i] = '\0';
  }
  return 0;
}


int imprimirmatriz(int f, char matriz[f][C]){
  for (int fila = 0; fila < f; fila++){
    printf("\t");
    for ( int i = 0; matriz[fila][i] != '\0'; i++){
      printf("%c", matriz[fila][i]);
    }
    printf("\n");
  }
  return 0;
}


int ordenarmatriz(int f, char matriz[f][C]){
  char l0 = '\0', l1 = '\0', aux[C];
  for (int i = 0; i < f; i++){
    for (int j = 0; j < f-1; j++){

      //Paso de mayuscula a minuscula (solo para comparar).
      l0 = matriz[j][0];
      if (matriz[j][0] >= 65 && matriz[j][0] <= 90){l0 += 32;}
      l1 = matriz[j+1][0];
      if (matriz[j+1][0] >= 65 && matriz[j+1][0] <= 90){l1 += 32;}
      //

      if (l0 > l1){
        strcpy(aux, matriz[j+1]);
        strcpy(matriz[j+1], matriz[j]);
        strcpy(matriz[j], aux);
      }
    }
  }
  return 0;
}


int main(){
  int f;
  printf("Ingrese la cantidad de filas en la matriz: ");
  scanf("%d", &f);
  char matriz[f][C];
  cargarmatriz(f, matriz);
  printf("\nTextos Ingresados:\n\n");
  imprimirmatriz(f, matriz);
  ordenarmatriz(f, matriz);
  printf("\nTextos Ordenados:\n\n");
  imprimirmatriz(f, matriz);
  return 0;
}