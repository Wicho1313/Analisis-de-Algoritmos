#include <stdio.h>
#include <string.h>

long saltos(long n, long m,long s[]){
    int i;
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(s[n]==0){
        for(i=1;i<=m;i++){
            s[n]+=saltos(n-i,m,s);
        }
    }
    return s[n];
}

int main(){
    long n,k;
    scanf("%ld %ld",&n, &k);
    long s[n+1];
    memset(s,0,sizeof(long)*(n+1));
    long result=saltos(n,k,s);
    printf("%ld",result);
}
