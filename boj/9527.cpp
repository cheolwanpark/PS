#include <stdio.h>

typedef unsigned long long llu;

llu g[56]={0};
llu k[56]={0};

void calcG() {
  g[1] = 1;
  llu s = g[1];
  for(int i=2; i<=55; ++i) {
    g[i] = s + (1ULL<<(i-1));
    s += g[i];
  }
}

void calcK() {
  k[0] = 0;
  for(int i=1; i<=55; ++i) {
    k[i] = k[i-1] + g[i];
  }
}

llu msb(llu n) {
  llu k = 1, r = 0;
  for(llu i=0; k<=n; ++i) {
    r = i;
    k *= 2;
  }
  return r;
}

llu solve(llu n) {
  if(n == 0) return 0;
  auto m = msb(n);
  auto r = n - (1ULL << m);
  return solve(r) + k[m] + r + 1;
}

int main() {
  calcG();
  calcK();
  llu A, B;
  scanf("%llu%llu", &A, &B);
  printf("%llu\n", solve(B) - solve(A-1));
}