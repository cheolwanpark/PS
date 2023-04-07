#include <stdio.h>
#include <algorithm>
using namespace std;

const int INF = 987654321;

constexpr int fullmask(int N) {
  return (1 << N) - 1;
}

int N;
int W[16][16];

int memo[16][16][fullmask(16)]={0,};
int solve(int start, int cur, int mask) { // start에서 시작해서 cur에 도착하면서 cur 이전에 mask만큼의 도시를 거친 비용중 최솟값
  if(start == cur) {
    return mask == 0 ? 0 : INF;
  } else if(mask == 0) {
    return INF;
  } else if(memo[start][cur][mask] > 0) {
    return memo[start][cur][mask];
  }
  
  memo[start][cur][mask] = INF;
  for(int i=0; i<N; ++i) {
    if(((1 << i) & mask) && W[i][cur] > 0) {
      memo[start][cur][mask] = min(memo[start][cur][mask], solve(start, i, mask & (~(1 << i))) + W[i][cur]);
    }
  }
  memo[start][cur][mask] = min(memo[start][cur][mask], INF);
  return memo[start][cur][mask];
}

int main() {
  scanf("%d", &N);
  for(int i=0; i<N; ++i) {
    for(int j=0; j<N; ++j) scanf("%d", &W[i][j]);
  }

  int mn = INF;
  for(int i=0; i<N; ++i) {
    for(int j=0; j<N; ++j) {
      if(W[j][i] > 0) {
        int mask = (~(1 << j));
        mn = min(mn, solve(i, j, fullmask(N) & mask) + W[j][i]);
      }
    }
  }
  printf("%d\n", mn);
}

// 반례: https://www.acmicpc.net/board/view/51533