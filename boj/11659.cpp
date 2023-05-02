#include <stdio.h>

int main() {
  int N, M, n, a, b, S[100001]={0};
  scanf("%d%d", &N, &M);
  for(int i=1; i<=N; ++i) {
    scanf("%d", &n);
    S[i] = S[i-1] + n;
  }
  for(int i=0; i<M; ++i) {
    scanf("%d%d", &a, &b);
    printf("%d\n", S[b] - S[a-1]);
  }
}