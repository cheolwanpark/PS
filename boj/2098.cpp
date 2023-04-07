#include <stdio.h>
#include <algorithm>
using namespace std;

const int INF = 987654321;

constexpr int fullmask(int N) {
  return (1 << N) - 1;
}

int N;
int W[16][16];

int memo[16][fullmask(16)]={0,};
int solve(int cur, int mask) {
  if(cur == 0) {
    return mask == 0 ? 0 : INF;
  } else if(mask == 0) {
    return INF;
  } else if(memo[cur][mask] > 0) {
    return memo[cur][mask];
  }
  
  memo[cur][mask] = INF;
  for(int i=0; i<N; ++i) {
    if(((1 << i) & mask) && W[i][cur] > 0) {
      memo[cur][mask] = min(memo[cur][mask], solve(i, mask & (~(1 << i))) + W[i][cur]);
    }
  }
  memo[cur][mask] = min(memo[cur][mask], INF);
  return memo[cur][mask];
}

int main() {
  scanf("%d", &N);
  for(int i=0; i<N; ++i) {
    for(int j=0; j<N; ++j) scanf("%d", &W[i][j]);
  }

  int mn = INF;
  for(int i=0; i<N; ++i) {
    if(W[i][0] > 0) {
      int mask = (~(1 << i));
      mn = min(mn, solve(i, fullmask(N) & mask) + W[i][0]);
    }
  }
  printf("%d\n", mn);
}