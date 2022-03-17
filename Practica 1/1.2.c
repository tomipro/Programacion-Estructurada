#include <stdio.h>

int main(void){
    int num1, num2;
    char car = ' ';
    int funcion = 0;
    int res = 0;

    printf("Ingrese primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese segundo numero: ");
    scanf("%d", &num2);

    fflush(stdin);
    printf("Ingrese una operacion [+ - * /]: ");
    car = getchar();

    if (car == "+"){
        funcion += num1 + num2;
        // res += funcion;
    }
    else if (car == "-"){
        funcion += num1 - num2;
        // res += funcion;
    }
    else if (car == "*"){
        funcion += num1 * num2;
        // res += funcion;
    }
    else if (car == "/"){
        funcion += num1 / num2;
        // res += funcion;
    }

    printf("%d %s %d = %d\n", num1, &car, num2, res);
    // suma = num1 + num2;
    // printf("%d\n", suma);

    return 0;
}