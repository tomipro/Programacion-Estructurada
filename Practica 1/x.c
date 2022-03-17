#include <stdio.h>

int main(){
    float num;
    printf("Ingrese un numero real: ");
    scanf("%f", &num);
    int num2 = (int)num;
    printf("%d", num2);
    
    return 0;
}