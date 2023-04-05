#include <stdio.h>

int main() {
  int A, B, C, N, cnt[10]={0,};
  scanf("%d%d%d", &A, &B, &C);
  N = A*B*C;
  while(N > 0) {
    cnt[N%10]++;
    N /= 10;
  }
  for(int i=0; i<10; ++i) {
    printf("%d\n", cnt[i]);
  }
}