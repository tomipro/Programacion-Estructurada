#include <stdio.h>
#include <math.h>

void redondear(double *numero)
{
    *numero = round(*numero);
}

int main()
{
    double n;
    scanf("%lf", &n);
    printf("%lf = ", n);
    redondear(&n);
    printf("%lf\n", n);
    return 0;
}