// R E C U R S I V I D A D
// tarea: hacer ejercicios (existe resolucion)

#include <stdio.h>

int prodR(int a, int b){
    int res;

    if (b != 0){
        res = a + prodR(a, b - 1);
    }

    else {
        res = 0;
    }
    return res;
}


int main(void){

    // funR(2);
    // printf("%d\n", sumR(6));
    printf("%d\n", prodR(5, 3));

    return 0;
}
/*
void funR(int c)
{
    if (c != 0)
    {
        printf("%s#%d\n", "hola", c);
        funR(c - 1);
        printf("%s#%d\n", "chau", c);
    }
}
*/


/*
int sumR(int n){
    if ( n != 0){
        return n + sumR(n - 1);
    }
    else {
        return 0;
    }
}
*/

/*
int sumR(int n){
    int res;

    if ( n != 0){
        res = n + sumR(n - 1);
    }
    else {
        res = 0;
    }
    return res;
}
*/