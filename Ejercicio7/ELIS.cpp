#include<iostream>
#include<vector>
using namespace std;

int LIS(vector<int> &lista, vector<int> &num){
	int lis=-1;
	for(int i=0; i<lista.size(); i++){
		int aux=1;
		int auxM=1;
		for(int j=0; j<i; j++){
			if(lista[j]<lista[i]){
				aux=max(1, num[j] + 1);	
				auxM=max(aux, auxM);
			}
		}
		num[i]=auxM;
	}
	for(int s=0; s<num.size(); s++)
		lis=max(lis, num[s]);
	return lis;
}

int main(){
	int n;
	cin >> n;
	vector<int> lista(n);
	vector<int> num(n);
	for(int i = 0; i < n; i++)
		cin >> lista[i];

	cout << LIS(lista, num) << "\n";
	return 0;
}
