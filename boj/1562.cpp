#include <stdio.h>

int MOD = 1000000000;
int solve(int N) {
  int memo[101][10][1024]={0};
  for(int i=0; i<=9; ++i) memo[1][i][1<<i] = 1;
  for(int i=2; i<=N; ++i) {
    for(int j=0; j<=9; ++j) {
      for(int m=0; m<=1023; ++m) {
        if(j != 0) memo[i][j][m | (1 << j)] = (memo[i][j][m | (1 << j)] + memo[i-1][j-1][m]) % MOD;
        if(j != 9) memo[i][j][m | (1 << j)] = (memo[i][j][m | (1 << j)] + memo[i-1][j+1][m]) % MOD;
      }
    }
  }
  int r = 0;
  for(int i=1; i<10; ++i) {
    r = (r + memo[N][i][1023]) % MOD;
  }
  return r;
}

int main() {
  int N;
  scanf("%d", &N);
  printf("%d\n", solve(N));
}