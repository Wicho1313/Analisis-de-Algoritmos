#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int algo1, int algo2){
  if (algo1<algo2) {
    return algo2;
  }
  else{
    return algo1;
  }
}

int lcs(char c1[],char c2[], int i, int j,int tam1, int tam2,int mat[tam1][tam2]){
  if (i==tam1 || j==tam2) {
    return 0;
  }
  if (c1[i]==c2[j]) {
    if (mat[i][j] == -1) {
      mat[i][j]=1+lcs(c1,c2,i+1,j+1,tam1,tam2,mat);
    }
    return mat[i][j];
  }else{
    if (mat[i][j] == -1) {
      mat[i][j]=max(lcs(c1,c2,i,j+1,tam1,tam2,mat),lcs(c1,c2,i+1,j,tam1,tam2,mat));
    }
    return mat[i][j];
  }
}

int main(int argc, char const *argv[]) {
  char c1[1000], c2[1000];
  int i,j;
  scanf("%s",&c1);
  scanf("%s",&c2);
  int tam1 = strlen(c1);
  int tam2 = strlen(c2);
  int mat[tam1][tam2];

  for (i = 0; i < tam1; i++) {
    for (j = 0; j < tam2; j++) {
      mat[i][j]=-1;
    }
  }
  printf("%i",lcs(c1,c2,0,0,tam1,tam2,mat));
  return 0;
}
