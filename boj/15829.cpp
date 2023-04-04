#include <stdio.h>

typedef unsigned long long llu;
const llu R = 31;
const llu M = 1234567891;

llu r(int n) {
  llu res = 1;
  for(int i=0; i<n; ++i) {
    res = (res * R) % M;
  }
  return res;
}

llu char2code(char c) {
  return (llu)(c - 'a' + 1);
}

int main() {
  int L;
  char s[51];
  scanf("%d%s", &L, s);
  
  llu hash = 0;
  for(int i=0; i<L; ++i) {
    hash = (hash + char2code(s[i]) * r(i)) % M;
  }
  printf("%llu\n", hash);
}