#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
char* dinArrCD(char* arrCD, int t){
    arrCD = malloc(t);
    return arrCD;
    // return (char*) malloc(t);
}

int main(void){
    char* arrCD = NULL;
    arrCD = dinArrCD(arrCD, 8);
    strcpy(arrCD, "chau");

    printf("\narrCD - > %s\n", arrCD);
    
    free(arrCD);

    return 0;
}
*/

void fun (int* x){
    *x = *x + 1;
}

int main(void){
    int x = 1;
    fun(&x);
    printf("%c", x);

    return 0;
}