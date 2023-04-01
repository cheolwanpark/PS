#include <stdio.h>

int is666(int N) {
  int six = 0;
  while(N > 0) {
    if(N%10 == 6) {
      ++six;
      if(six >= 3) return true;
    } else {
      six = 0;
    }
    N /= 10;
  }
  return false;
}

int main() {
  int N, n=666;
  scanf("%d", &N);
  while(true) {
    if(is666(n)) {
      --N;
      if(N <= 0) break;
    }
    ++n;
  }
  printf("%d\n", n);
}