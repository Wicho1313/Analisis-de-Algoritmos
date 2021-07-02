#include <stdio.h>  
#include<string.h>  
#include <math.h>  
#include <windows.h>  
//prototipos de funciones  
int log2(int);  
void regla (int, int, int);  
void menu();  
//Main  
int main (void){  
    int tam, ttam, opc;  
    do{  
        menu();  
        scanf("%d", &opc);  
        switch(opc){  
            case 1:  
                printf ("\nIngresa el tamano del arreglo: ");  
                scanf("%d", &tam);  
                ttam=log2(tam);  
                regla(ttam,1,1);  
                for(int i=0;i<ttam;i++){  
                    printf ("--");  
                }  
                printf ("\n");  
            break;  
            case 2:  
                printf("\n Gracias, hasta luego. \n\n\n");  
            break;  
            default:  
                printf("\nOpci%cn incorrecta, intente de nuevo\n\n", 162);  
        }  
        system("pause");  
    }while(opc!=2);  
    return 0;  
}  
//Funciones  
void menu(){  
    system("cls");  
    printf ("\n     Pr%cctica #3 Regla con Divide y Venceras", 160);  
    printf ("\nAn%clisis de Algoritmos      Grupo: 3CM4", 160);  
    printf ("\nAlumnos: \n Orozco Z%crate Jes%cs \n Torres Mora Jos%c Eduardo", 160, 163, 130);  
    printf ("\n\n Men%c ", 163);  
    printf ("\n 1) Regla");  
    printf ("\n 2) Salir");  
    printf ("\nIngrese opci%cn: ", 162);      
}  
int log2(int n){  
    float f=(log(n)/log(2));  
    int ent=f;  
    if(f-ent){  
        log2(n+1);  
    }  
    else  
        return n;  
}  
  
void regla(int N,int aux,int n){  
    int i, j;  
    if(N>2){  
        for(i=0;i<aux;i++){  
            for(j=0;j<N-1;j++){  
                printf (" ");  
            }  
            printf ("|");  
        }  
        printf ("\n");  
        regla(N/2,(pow(2,n))+aux,n+1);
        regla (1-(N/2), 1, 0);
    }else if(N==2){   
        for(i=0;i<aux;i++){  
            for(int j=0;j<N/2;j++){  
                printf(" ");  
            }  
            printf ("|");  
        }  
        printf("\n");  
    }  
}  
