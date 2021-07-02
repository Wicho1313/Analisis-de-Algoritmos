#include <stdio.h>

int main (void){
	int i,n,cont=0;
	scanf("%d",&n);
	for(i=1;i<n*2;i*=6){
		printf("ALGORITMOS %d\n",++cont);
	}
}
