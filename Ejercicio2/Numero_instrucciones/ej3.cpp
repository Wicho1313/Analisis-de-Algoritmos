#include <stdio.h>

int main(void){
	int n,j,i,cont=0;
	scanf("%d",&n);
	i=n;
	while(i>=0){
		for(j=n;i<j;i-=2,j/=2){
			printf("ALGORITMOS %d\n",cont++);
		}
	}
	return 0;
}
