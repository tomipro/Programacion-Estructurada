#include <stdio.h>

int main(void){
    float num;
    // int redondeo, piso, techo;

    printf("Ingrese un numero real: ");
    scanf("%d", &num);

    int n = (int)(num - 0.5);
    printf("%d\n", n);

    return 0;
}