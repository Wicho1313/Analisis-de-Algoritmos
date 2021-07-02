#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int N;
string esp;
int main(){
	int TC,tc=1,i=0,k=0;
	scanf("%d",&TC);
	for(tc=1;tc<=TC;++tc){
		printf("Caso %d: ",tc);
		scanf("%d",&N);
		cin >> esp;
		while(i < N){
			if(esp[i] == '.'){
				++k;
				i += 3;
			} else {
				++i;
			}
		}
		printf("%d\n",k);
	}
	return 0;
}
