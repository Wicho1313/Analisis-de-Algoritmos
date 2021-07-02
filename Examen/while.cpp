#include <stdio.h>
int main (){
	int i,j,n,c=0;
	scanf("%d",&n);
	i=5*n;
	while(i>=0){
		for(j=n;j>1;j/=2){
			//printf("wea");
			c++;
			i-=2;
		}
	}
	printf("%d",c);
}
