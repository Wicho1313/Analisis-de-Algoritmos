#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string.h>
typedef long long int lli;

using namespace std;
struct Punto{                                                 // Estructura de un Punto.
   double x;
   double y;
 };
void Busca(struct Punto *,int);
int Ordenax(const void *,const void *);
double Distancia(struct Punto,struct Punto);
double MinimaDistancia=1e10;                                  // Mínima distancia.


int main()
{
   int a,n;                                                   //Algunas variables
   double x,y;
   cin>>n;                                                    //Obten n
   struct Punto p[n];                                         //Declara el arreglo de puntos

   for(int i=0;i<n;i++)                                       // Obten los datos
   {
      scanf(" %lf %lf",&x,&y);
      p[i].x=x;
      p[i].y=y;
    }

   Busca(p,n);                                                //Busca la minima distancia

   printf("%.3lf\n",MinimaDistancia);

   return(0);
 }

void Busca(struct Punto *p,int n)
{
   double d;
   int i,j,a,b;

   if(n<=1)                                                   // Si no hay pares de puntos:
      return;                                                 // salir.
    
   qsort(p,n,sizeof(struct Punto),Ordenax);                   // Ordenar los puntos por la coordenada x.
   
   Busca(p,n/2);                                              // Mirar en el subconjunto de la izquierda.

   Busca(p+n/2,(n+1)/2);                                      // Mirar en el subconjunto de la derecha.
   															  //Busca del lado derecho e izquiero los puntos mas cercanos 
   for(i=n/2; (i>0) && (p[n/2].x-p[i].x<MinimaDistancia); i--); // Hallar los límites del conjunto central.

   for(j=n/2; j<n-1 && p[j].x-p[n/2].x<MinimaDistancia; j++);	//Búsqueda en el conjunto central.
   for( a = i ; a <= j ;a ++)
      for( b = a + 1 ; b <= j ; b++)
         if((d=Distancia(p[a],p[b]))<MinimaDistancia)          //Si encuentras una distancia mínima actualizala
         {
            MinimaDistancia=d;
          }
 }


int Ordenax(const void *a,const void *b){
   return(((*(struct Punto *)a).x<(*(struct Punto *)b).x)?-1:1);     //Manera en que se comparan los puntos x
 }

double Distancia(struct Punto a,struct Punto b){                     // Función que calcula la distancia entre dos puntos.
   return(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
 }
