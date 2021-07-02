#include <stdio.h>

int main(void){
	int n,j,i,cont=0;
	scanf("%d",&n);
	for(j=n;j>1;j/=2){
		if(j<(n/2)){
			for(i=0;i<n;i+=2){
			//	printf("ALGORITMOS\n");
			cont++;
			}
		}
	}
	printf(" %d\n",cont);
	return 0;
}
