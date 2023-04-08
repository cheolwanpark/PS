#include <stdio.h>

int main() {
  int N, X, n;
  scanf("%d%d", &N, &X);
  for(int i=0; i<N; ++i) {
    scanf("%d", &n);
    if(n < X) printf("%d ", n);
  }
  printf("\n");
}