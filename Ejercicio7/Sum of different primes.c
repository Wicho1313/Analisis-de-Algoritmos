#include <stdio.h>
#include <string.h>
 
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, /* Code truncated, all the primes up until 1120, the last prime i 1129 */ };
int N, K;
int dp[1150][20][200];
 
int solve(int n, int k, int i) {
    if (n > 0 && k == 0) return 0;
    if (k == 0 && n == 0)
        return 1;
    if (n < 0 || k < 0) return 0;
    if (primes[i] > N) return 0;
    if (dp[n][k][i] != -1) return dp[n][k][i];
 
    return dp[n][k][i] = solve(n - primes[i], k-1, i+1) + solve(n, k, i+1);
}
 
int main() {
	int i, j ,k;
    //int aux[1150][20][200];
	while (scanf("%d %d", &N, &K), (N || K)) {
        memset(dp, -1, sizeof dp);
        //printf("%d\n", solve(N, K, 0));
        //aux=solve(N, K, 0);
    }
    for(i=0;i<1150;i++){
    	for(j=0;j<20;j++){
    		for(k=0;k<200;k++){
    			printf("%d\n",solve(N, K, 0));
			}
		}
	}
}
