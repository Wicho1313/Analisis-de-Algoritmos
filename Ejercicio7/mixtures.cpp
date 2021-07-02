#include <bits/stdc++.h>
using namespace std;

#define MAX 100+10
int n,valores[MAX],m[MAX][MAX];

int mix(int l,int r){
	if(m[l][r] != -1)
		return m[l][r];
	if(l == r)
		return 0;
	if(l+1 == r)
		return (valores[l]-valores[l-1])*(valores[r]-valores[r-1]);
	
	int res = 1<<20;
	for(int i=l; i<r; i++){
		int tmp=((valores[i]-valores[l-1])%100)*((valores[r]-valores[i])%100);
		res=min(res,tmp+mix(l,i)+mix(i+1,r));
	}
	m[l][r]=res;
	return res;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	while(cin>>n){
		for(int i=0; i<MAX; i++)
			for(int j=0; j<MAX; j++)
				 m[i][j]=-1;
		
		valores[0]=0;
		for(int i=1; i<=n; i++){
			cin>>valores[i];
			valores[i] += valores[i-1];
		}
		cout<<mix(1,n)<< "\n";
	}
}
