#include <bits/stdc++.h>
using namespace std;
typedef long long int ull;

int main(){
	int n;						//Se declara la variable en donde.
	cin >> n;					//se define como tamaño del arreglo.
	vector<ull> A(n);			//se hace un vector A con el tamaño n.
	for(int i = 0; i < n; ++i){	//ciclo que agrega el tamaño al vector.
		cin >> A[i];			//se introduce número por número.
	}
	ull ans = A[0];				//arreglo que tendrá la suma más grande (resultado).
	ull tmp_max = A[0];			//arreglo que tendrá la máxima suma hasta el momento.
	for(int i = 1; i < n; ++i){	//ciclo en el que se hacen las sub-sumas.
		tmp_max = max(tmp_max + A[i], A[i]);	//se suman los elementos contiguos.
		ans = max(tmp_max, ans);				//se saca el número máximo.
	}
	cout << ans;				//arroja la suma máxima.
	return 0;
}
