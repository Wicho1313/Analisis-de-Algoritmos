#include <bits/stdc++.h>
using namespace std;
typedef long long int ull;

int main(){
	int n;						//Se declara la variable en donde.
	cin >> n;					//se define como tama�o del arreglo.
	vector<ull> A(n);			//se hace un vector A con el tama�o n.
	for(int i = 0; i < n; ++i){	//ciclo que agrega el tama�o al vector.
		cin >> A[i];			//se introduce n�mero por n�mero.
	}
	ull ans = A[0];				//arreglo que tendr� la suma m�s grande (resultado).
	ull tmp_max = A[0];			//arreglo que tendr� la m�xima suma hasta el momento.
	for(int i = 1; i < n; ++i){	//ciclo en el que se hacen las sub-sumas.
		tmp_max = max(tmp_max + A[i], A[i]);	//se suman los elementos contiguos.
		ans = max(tmp_max, ans);				//se saca el n�mero m�ximo.
	}
	cout << ans;				//arroja la suma m�xima.
	return 0;
}
