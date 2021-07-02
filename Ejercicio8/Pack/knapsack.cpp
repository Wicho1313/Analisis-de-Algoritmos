#include<bits/stdc++.h>

using namespace std;

int ks(int W, vector<int>wt, vector<int> val)
{
	int i,w;
	int k[val.size()+1][W+1];
	for(int i = 0; i <= val.size(); i++)
		for(w = 0; w <= W; w++)
		{
			if(i == 0 || w == 0)
				k[i][w] = 0;
			else if(wt[i-1] <= w)
				k[i][w] = max(val[i-1] + k[i-1][w-wt[i-1]],  k[i-1][w]);
			else
				k[i][w] = k [i - 1][w];
		}
	return k[val.size()][W];
}

int main()
{
	int n , w, a, b;
	cin>>w>>n;
	vector<int>wt(n);
	vector<int>val(n);
	for(int i = 0; i < n; i++)
	{
		cin>>a>>b;
		wt[i]=a;
		val[i]=b;
	}
	cout<<ks(w,wt,val)<<endl;
}