#include <algorithm>
#include <iostream>
#include <vector>
#include <string.h>
typedef long long int lli;

using namespace std;
lli  MergeSortInversiones(lli Numeros[], lli ArrayTemporal[], lli Izquierda, lli Derecha);
lli Merge(lli Numeros[], lli ArrayTemporal[], lli Izquierda, lli Centro, lli Derecha);


/* Crea un array temporal y llama a merge sort*/
lli MergeSort(lli Numeros[], lli n)
{
    lli *ArrayTemporal = (lli *)malloc(sizeof(lli)*n);
    return MergeSortInversiones(Numeros, ArrayTemporal, 0, n - 1);
}
//Realiza el merge sort y regresa el número de inversiones
lli MergeSortInversiones(lli Numeros[], lli ArrayTemporal[], lli Izquierda, lli Derecha)
{
  lli Centro, NumInversiones = 0;
  if (Derecha > Izquierda)
  {
    
    Centro = (Derecha + Izquierda)/2;                                                    //Divide el arreglo en 2 partes
 
    NumInversiones  = MergeSortInversiones(Numeros, ArrayTemporal, Izquierda, Centro);
    NumInversiones += MergeSortInversiones(Numeros, ArrayTemporal, Centro+1, Derecha);
    NumInversiones += Merge(Numeros, ArrayTemporal, Izquierda, Centro+1, Derecha);        //Combina las 2 partes
  }
  return NumInversiones;
}
 
///Combina 2 arreglos ordenados y regresa el número de inversiones de los arreglos
lli Merge(lli Numeros[], lli ArrayTemporal[], lli Izquierda, lli Centro, lli Derecha)
{
  lli i, j, k;
  lli NumInversiones = 0;
 
  i = Izquierda;                                               //Indice del subarray izquierdo
  j = Centro;                                                   //Indice del subarray derecho
  k = Izquierda;                                                //Indice del subarray combinado resultante
  while ((i <= Centro - 1) && (j <= Derecha))
  {
    if (Numeros[i] <= Numeros[j]){
      ArrayTemporal[k++] = Numeros[i++];
    }
    else{
      ArrayTemporal[k++] = Numeros[j++];
      NumInversiones += (Centro - i);                           //Si no esta ordenado hay Centro-i inversiones
    }
  }
 
  
  while (i <= Centro - 1)                                         //Copia los elementos restantes del subarray Izquierdo al array temporal 
    ArrayTemporal[k++] = Numeros[i++];
 
  while (j <= Derecha)                                            //Copia los elementos restantes del subarray Derecho al array temporal 
    ArrayTemporal[k++] = Numeros[j++];
 
  for (i=Izquierda; i <= Derecha; i++)                            //Copia los elementos mezclados al array original
    Numeros[i] = ArrayTemporal[i];
 
  return NumInversiones;
}

int main(){
  lli t=0;                                                        //Obtenemos el número de casos
  cin>>t;                                                         //Obtenemos el número de casos
  char resultado[100000]="";                                      //Donde guardaremos la respuesta

  for (lli i = 0; i < t; ++i){
    lli n=0;
    cin>>n;
    lli Numeros[n];
        for(lli i=0; i<n;i++)
        {
                 cin>>Numeros[i];                                  // Se lee el numero           
        }
        sprintf(resultado+strlen(resultado),"%lld\n",MergeSort(Numeros, n));
        n=0;
  }
  printf("%s\n",resultado );  
  return 0;
}
