#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

const int INF = 987654321;

int N, M;
int m[100], c[100];
int memo[10000001];

int main() {
  scanf("%d%d", &N, &M);
  for(int i=0; i<N; ++i) scanf("%d", m+i);
  for(int i=0; i<N; ++i) scanf("%d", c+i);
  for(int i=0; i<=M; ++i) memo[i] = INF;

  for(int i=0; i<N; ++i) {
    for(int j=M; j>=0; --j) {
      if(j - m[i] <= 0) {
        memo[j] = min(memo[j], c[i]);
      } else {
        memo[j] = min(memo[j], memo[j-m[i]] + c[i]);
      }
    }
  }
  printf("%d\n", memo[M]);
}