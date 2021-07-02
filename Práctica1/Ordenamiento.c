/*
Compilación: gcc Ordenamiento.c -o Ordenamiento 

ejecución: ./Ordenamiento [arg1] [agrg2]

siendo: arg1= Numeros a ordenar
		arg2= Algorimto [i<=6]

1 para burbuja simple
2 para burbuja optimizada
3 para insercion
4 para seleccion
5 para shell 
6 para arbol binario
*/
#include <stdio.h>
#include "Algoritmos.c"

int main(int argc, char const *argv[])
{
	int tam, algoritmo;
	if (argc < 3)
		printf("Por favor ingrese el tamaño del arreglo como primer argumento\ny el algoritmo a usar como segundo argumento.\n");
	else
	{
		tam = atoi (argv [1]);					//primer argumento se ingresa el tamaño del arreglo
		algoritmo = atoi (argv [2]);			//segundo argumento que se espera la elección de un algoritmo
	}
	Algoritmos (algoritmo, tam);
	return 0;
}