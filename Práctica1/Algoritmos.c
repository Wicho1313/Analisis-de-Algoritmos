#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arbol.c"
#include "tiempo.c"
#include "funciones.h"

int i, j, aux;																//Variables globales para manejar los ciclos y temporal
double utime0, stime0, wtime0,utime1, stime1, wtime1;						//Variables para calcular el tiempo

void Algoritmos (int algoritmo, int tam)
{
	int * Arreglo = (int *) malloc (sizeof (int) * tam);						//arreglo dinámico para el tamaño del arreglo
	Arreglo = leerArchivo (Arreglo, tam);										//se abre el archivo donde contiene los numeros desordenados
	
	switch (algoritmo)
	{
		case 1:
		printf("Eligió el algoritmo de burbuja simple\n");
			Burbuja_Simple (Arreglo, tam);										
			break;
		case 2:
		printf("Eligió el algoritmo de burbuja Optimizada\n");
			Burbuja_Optimizada (Arreglo, tam);									
			break;
		case 3:
		printf("Eligió el algoritmo de Inserción\n");
			Insercion (Arreglo, tam);											
			break;
		case 4:
		printf("Eligió el algoritmo de Selección\n");
			Seleccion (Arreglo, tam);											
			break;
		case 5:
		printf("Eligió el algoritmo Shell\n");
			Shell (Arreglo, tam);												
			break;
		case 6:
		printf("Eligió el algoritmo de Arbol Binario\n");
			Arbol_Binario (Arreglo, tam);										
			break;
		default:
			printf("Opción invalida. Por favor seleccione del 1-6\n\n");
			exit (0);
	}
}

int * leerArchivo (int * Arreglo, int tam)
{
	FILE * Desordenados;
	Desordenados= fopen ("numeros10millones.txt", "r");									//Se abre el archivo proporcionado por el profesor
	if (Desordenados == NULL)
	{
		printf("Error al abrir el archivo con los numeros desordenados.\n\n\n");
		exit (0);
	}
	for (i = 0; i < tam; i ++)
		fscanf (Desordenados, "%d", &Arreglo [i]);								//Guardamos los numeros obtenidos del archivo en el arreglo dinamico
	Arreglo [i] = '\0';
	fclose (Desordenados);
	return Arreglo;
}

void Imprime_Numeros (int * Arreglo, int tam)
{
	FILE * Ordenados;
	Ordenados = fopen ("Salidas/Numeros_Ordenados.txt", "w");
	if (Ordenados == NULL)
	{
		printf("Error al crear el archivo con los %d numeros ordenados \n", tam);
		exit (0);
	}
	for (i = 0; i < tam; i ++)
		fprintf(Ordenados, "%d\n", Arreglo [i]);						//Se imprimen los numeros ordenados en el archivo creado
	free (Arreglo);
	fclose (Ordenados);
	printf("Nuevo archivo de texto creado en donde se encuentran los numeros ordenados\n");
}

void Tiempos (double utime0, double stime0, double wtime0, double utime1, double stime1, double wtime1, int tam)
{

	printf("Calculando el tiempo de ordenar %d numeros\n\n", tam); //se imprime la cadena con el algoritmo que fue utilizado segun sea el caso
	printf("Tiempo total:  %.10f s\n",  wtime1 - wtime0);
	printf("Tiempo de procesamiento en CPU: %.10f s\n",  utime1 - utime0);
	printf("Tiempo en acciónes de E/S:  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall:   %.10f %% \n\n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	
	//Mostrar los tiempos en formato exponecial
	printf("En formato exponencial:\n");
	printf("Tiempo total:  %.10e s\n",  wtime1 - wtime0);
	printf("Tiempo de procesamiento en CPU: %.10e s\n",  utime1 - utime0);
	printf("Tiempo en acciónes de E/S:  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall:   %.10f %% \n\n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
}

void Burbuja_Simple (int * Arreglo, int tam)
{
	uswtime(&utime0, &stime0, &wtime0);										//Se toma el tiempo antes de empezar el algoritmo
	for (i = 1; i < tam; i ++)
		for (j = 0; j < (tam - 1); j ++)
		{
			if (Arreglo [j] > Arreglo [j + 1])
			{
				aux = Arreglo [j];
				Arreglo [j] = Arreglo [j + 1];
				Arreglo [j + 1] = aux;
			}
		}
	uswtime(&utime1, &stime1, &wtime1);											//Se termina de tomar el tiempo justo después de que acabe
	Tiempos (utime0, stime0, wtime0, utime1, stime1, wtime1, tam);		//Calculamos el tiempo del algoritmo 
	Imprime_Numeros (Arreglo, tam);											//Se crea un archivo para visualizar los numeros ordenados
}

void Burbuja_Optimizada (int * Arreglo, int tam)
{
	char cambios [3] = "No";
	uswtime(&utime0, &stime0, &wtime0);										
	for (i = 1; ((i < tam) && strcmp (cambios, "No") == 0); i ++)
		for (j = 0; j < tam; j ++)
		{
			if (Arreglo [i] < Arreglo [j])
			{
				aux = Arreglo [j];
				Arreglo[j] = Arreglo [i];
				Arreglo[i] = aux;
				strcpy (cambios, "si");
			}
		}
	
/*
	char cambios[3]="No";
	uswtime(&utime0, &stime0, &wtime0);		
	i=0;
	while((i<(tam-1)) && (strcmp(cambios, "No")!=0)){
		strcpy(cambios,"No");
	
	for(j=0;j<((tam-2)-i);j++){
		if(Arreglo[i]<Arreglo[j]){
			aux=Arreglo[j];
			Arreglo[j]=Arreglo[i];
			Arreglo[i]=aux;
			strcpy(cambios,"Si");
			}
		}
		i=i+1;
	}
*/
	uswtime(&utime1, &stime1, &wtime1);										
	Tiempos (utime0, stime0, wtime0, utime1, stime1, wtime1, tam);		
	Imprime_Numeros (Arreglo, tam);											
}

void Insercion (int * Arreglo, int tam)
{
	uswtime(&utime0, &stime0, &wtime0);										
	for (i = 1; i < tam; i ++)
	{
		aux = Arreglo[i];
		j = i - 1;
		while ((Arreglo[j] > aux) && (j >= 0))
		{
			Arreglo[j + 1] = Arreglo[j];
			j --;
		}
		Arreglo[j + 1] = aux;
	}
	uswtime(&utime1, &stime1, &wtime1);										
	Tiempos (utime0, stime0, wtime0, utime1, stime1, wtime1, tam); 
	Imprime_Numeros (Arreglo, tam);											
}

void Seleccion (int * Arreglo, int tam)
{
	int p;
	uswtime(&utime0, &stime0, &wtime0);										
	for (i = 0; i < (tam - 1); i ++)
	{
		p = i;
		for (j = i + 1; j <= (tam - 1); j ++)
		{
			if (Arreglo[j] < Arreglo[p])
				p = j;
		}
		if (p != i)
		{
			aux = Arreglo[p];
			Arreglo[p] = Arreglo[i];
			Arreglo[i] = aux;
		}
	}
	uswtime(&utime1, &stime1, &wtime1);										
	Tiempos (utime0, stime0, wtime0, utime1, stime1, wtime1, tam);	
	Imprime_Numeros (Arreglo, tam);											
}

void Shell (int * Arreglo, int tam)
{
	int k = tam / 2;
	uswtime(&utime0, &stime0, &wtime0);										
	while (k > 0)
	{
		for (i = k; i < tam; i ++)
		{
			aux= Arreglo[i];
			j = i - k;
			while (j >= 0 && Arreglo[j] > aux)
			{
				Arreglo[j + k] = Arreglo[j];
				j -= k;
			}
			Arreglo [j + k] = aux;
		}
		k /= 2;
	}
	uswtime(&utime1, &stime1, &wtime1);										
	Tiempos (utime0, stime0, wtime0, utime1, stime1, wtime1, tam); 
	Imprime_Numeros (Arreglo, tam);											
}

void Arbol_Binario (int *Arreglo, int tam)
{
	uswtime(&utime0, &stime0, &wtime0);									
	Arreglo = InsertarABB(Arreglo,tam);
	uswtime(&utime1, &stime1, &wtime1);									
	Tiempos (utime0, stime0, wtime0, utime1, stime1, wtime1, tam);	
	Imprime_Numeros (Arreglo, tam);
}