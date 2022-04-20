#include <stdio.h>
#define TAM 50
#define TERM '\n'

void imprimirText(char arr[TAM]);
void cargarText(char arr[TAM]);
int largoArr(char arr[TAM]);
void normalizar(char arr[TAM]);
int espaciosArr(char arr[TAM]);


int main(void){
    char arr[TAM] = {0};
    
    cargarText(arr);
    normalizar(arr);
    imprimirText(arr);

    return 0;
}


void imprimirText(char arr[TAM]){
    printf("%s", arr);
}

void cargarText(char arr[TAM]){
    int i = 0;
    int aux;

    printf("Ingrese texto:\t");

    if (i < TAM - 1){
        fflush(stdin);
        aux = getchar();
    }
    
    while (aux != TERM && i < TAM - 1){
        arr[i] = aux;
        i++;
        if (i < TAM - 1){
            aux = getchar();
        }
        arr[i] = '\n';
    }
    
}

int largoArr(char arr[TAM]){
    int i = 0;

    for (i = 0; i < TAM - 1 && arr[i] != TERM; i++);
    return i - 1;
}
void normalizar(char arr[TAM]){
    int i = 0;
    int j = 0;
    int aAscii, largo;
    char arr2[TAM] = {0};

    if ( ! (arr[0] >= 'A' && arr[0] <= 'Z')){
        aAscii = (arr[0] - 32);
        arr[0] = (char) aAscii;
    }

    for (i = 0; i < TAM - 1 && arr[i] != TERM; i++){
        if (! (arr[i] == ' ' && arr[i + 1] == ' ')){
            arr2[j] = arr[i];
            j++;
        }
    }

    largo = largoArr(arr2);
    if (arr2[largo] != '.'){
        if (largo!=TAM-1){
            arr2[largo+1]='.';
            arr2[largo+2]='\0';
        }
            
        else{
            arr2[largo]='.';
        }
    }

}


// int ultimoPunto(char arr[TAM]);
// int normalizar(int arr[TAM]);

/*
int ultimoPunto(char arr[TAM]){
    int res = 0;

    if (arr[largoArr(arr)] != '.'){
        res = 1;
    }
    return res;
}
*/

/*
int espaciosArr(int arr[TAM]){
    int i, j;
    int res = 0;

    for (i = 0; arr[i] != TERM && i < TAM - 1 && res != 1; i++){
        for (j = 0; arr[j] != TERM && j < TAM - 1; j++){
            if (arr[i] == ' ' && arr[j] == ' '){
                res = 1;
            }
        }
    }
    return res;
}
*/

/*
int normalizar(int arr[TAM]){
    int res = 1;

    if ((arr[0] >= 'A' && arr[0] <= 'Z') && espaciosArr(arr) == 0 && ultimoPunto(arr) == 0){
        res = 0;
    }   
    return res;
}
*/

/*
//BIEN HECHO
#include <stdio.h>
#include <stdlib.h>
#define T 25
void cargarArr(char Arr[T]);
void imprimirText(char cadena[11]);
void normalizar(char Arr[T]);
int main(){
    char Arr[T]={0};
    cargarArr(Arr);
    return 0;
}


void cargarArr(char Arr[T]){
    int i=0;
    char aux;
    char term='\n';
    printf("Ingrese contenido: ");

    if(i<T-1)
        aux = getchar();
    while(aux!=term && i<T-1){
        Arr[i] = aux;
        i++;
        if(i<T-1)
            aux = getchar();
    }
    Arr[i]='\0';
    normalizar(Arr);
}


void imprimirText(char Arr[T]){
    printf("%s",Arr);
}

void normalizar(char Arr[T]){
    int c=0;
    int i;
    int j;
    for (i=0;i<=T-1;i++){
        if (i==0){
            if (Arr[i]<'A' || Arr[i]>'Z'){
                Arr[i]=Arr[i]-32;
            }
        }
        else if (i<T-1){
            if (Arr[i]==' ' && Arr[i-1]==' '){
                j=0;
                for (j=i;j+1<T-1;j++){
                    Arr[j]=Arr[j+1];
                }
                i=i-1;
            }
            if (Arr[i]=='\0' || i==T-2){
                    if (i==T-2 && Arr[i-1]!='.'){
                        Arr[i]='.';
                    }
                    else if (c==0 && Arr[i-1]!='.'){
                        Arr[i]='.';
                    }
                    c=1;
            }
        }
    }
        imprimirText(Arr);
}
*/
