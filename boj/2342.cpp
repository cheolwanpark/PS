#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int N = 1;
int p[100002]={0};
int memo[5][5][100001];

int cost(int prev, int next) {
  if(prev == 0) return 2;
  else if(next == 0) return INF;

  int diff = max(prev, next) - min(prev, next);
  if(diff == 0) return 1;
  else if(diff == 2) return 4;
  else return 3;
}

int calc(int l, int r, int n) {
  if(l == r) return INF;
  int res = INF;
  for(int i=0; i<=4; ++i) {
    res = min(res, memo[i][r][n-1] + cost(i, l));
    res = min(res, memo[l][i][n-1] + cost(i, r));
  }
  return min(res, INF);
}

int main() {
  while(true) {
    scanf("%d", &p[N]);
    if(p[N] == 0) break;
    ++N;
  }
  --N;

  for(int i=0; i<=4; ++i) {
    for(int j=0; j<=4; ++j) memo[i][j][0] = INF;
  }
  memo[0][0][0] = 0;

  for(int i=1; i<=N; ++i) {
    for(int j=0; j<=4; ++j) {
      for(int k=0; k<=4; ++k) {
        memo[j][k][i] = INF;
      }
    }
    for(int j=0; j<=4; ++j) {
      memo[j][p[i]][i] = calc(j, p[i], i);
      memo[p[i]][j][i] = calc(p[i], j, i);
    }
  }
  
  int mn = INF;
  for(int i=0; i<=4; ++i) {
    mn = min(mn, memo[i][p[N]][N]);
    mn = min(mn, memo[p[N]][i][N]);
  }
  printf("%d\n", mn);
}