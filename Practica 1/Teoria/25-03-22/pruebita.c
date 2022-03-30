#include <stdio.h>
#define TERM_C '\0'

int main(void){
    char arrC[8] = {TERM_C};
    arrC[0] = 'h';
    arrC[1] = 'o';
    arrC[2] = 'l';
    arrC[3] = 'a';
    arrC[4] = TERM_C;

    printf("%s\n", arrC);

    return 0;
}