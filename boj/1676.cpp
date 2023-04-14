#include <stdio.h>

int getDivs(int N, int d) {
  int r = 0;
  while(N%d == 0) {
    N /= d;
    r++;
  }
  return r;
}

int main() {
  int N, n2=0, n5=0;
  scanf("%d", &N);
  for(int i=2; i<=N; ++i) {
    n2 += getDivs(i, 2);
    n5 += getDivs(i, 5);
  }
  printf("%d\n", n2 > n5 ? n5 : n2);
}