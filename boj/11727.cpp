#include <stdio.h>

const int MOD = 10007;

int main() {
  int N, memo[1001];
  scanf("%d", &N);
  memo[1] = 1;
  memo[2] = 3;
  for(int i=3; i<=N; ++i) {
    memo[i] = 0;
    if(i - 2 > 0) memo[i] = (memo[i] + memo[i-2]*2) % MOD;
    if(i - 1 > 0) memo[i] = (memo[i] + memo[i-1]) % MOD;
  }
  printf("%d\n", memo[N]);
}