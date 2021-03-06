/**
02 fgets leer archivo txt
*/

#include <stdio.h>
#include <stdlib.h>
/**
    Prototipo de la función fgets:
        *fgets(char *str, int n, FILE *stream)
        *str: Es el arreglo donde se guarda la informacion leida
        n: es la cantidad de caracters a leer
        FILE*: Es el archivo a leer

     Comentarios:
        fgets lee de a n cantidades de caracteres
        fgets retona 0 cuando encuentra el fin del archivo
        Si str esta completo, se coloca un '\0' en la ultima posición del arreglo
        Si str No esta completo, se coloca un '\0' después del ultimo caracter leido

    link ejemplo: https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm


  \brief Lectura de un archivo txt (en cantidades de caracteres) que contiene nombres
        (simples o compuestos) uno por cada linea del archivo.

marianotrigila@gmail.com
*/

#define T 10                        /** defino la constante que dertermina la cantidad de caracteres a leer*/
int main()
{
    char str[T]={0};                /** declaro el arreglo donde voy a guardar el string que lee fgets. */
    int r;                          /** en r guardo lo que retorna fgets*/
	int res = 0;
	
    FILE* arch;                     /** Declaro la variable arch com tipo de dato FILE*  */
    arch=fopen("/Users/tomasprodan/Documents/Programacion Estructurada/Practica 1/Teoria/01-04-22/01j/02/arch.txt","r");     /** Abrir el archivo "arch.txt" de lectura. En arch queda el puntero que refrerencia al archivo*/

    if(arch!=NULL){                  /** Si el arch contiene NULL es porque el archivo no pudo ser abierto*/
		r= (int)fgets (str, T, arch);        /** LEER archivo. (antes del while) */
		while(r!=0)                          /** Mientras no sea fin de archivo*/
		{
			printf("%s",str);                /** Imprimir en pantalla la variable que contiene la información leida del archivo */
			r= (int)fgets (str, T, arch);    /** LEER archivo. (al final del while)  */
		}
		
		fclose(arch);                   /** cerrar el archivo arch" */
	} else{
		res = -1;                  /** Termina el programa */
	}
    return res;
}