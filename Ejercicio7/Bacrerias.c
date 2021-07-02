#include <stdio.h>

int min(int a, int b) { return (a < b)? b : a; }
 
int main (){
	int i, j, m, n;
	
	scanf("%d %d",&m, &n);
	
	int cuad[m][n], bact[m][n];
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&cuad[i][j]);
			bact[i][j]=0;
		}
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(i==0 && j==0){
				bact[i][j]=cuad[i][j];
			}
			else if(j==0){
				bact[i][j]=bact[i-1][j]+bact[i][j];
			}
			else if(i==0){
				bact[i][j]=bact[i][j-1]+bact[i][j];
			}
			else{
				bact[i][j]=min(bact[i][j-1],bact[i-1][j]+cuad[i][j]);
			}
		}
	}
	printf("%d \n",bact[m-1][n-1]+1);
	return 0;
}
