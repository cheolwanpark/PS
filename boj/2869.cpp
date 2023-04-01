#include <stdio.h>

int main() {
  int A, B, V;
  scanf("%d%d%d", &A, &B, &V);
  int d = (V - A) / (A - B), r = (V - A) % (A - B);
  printf("%d\n", r > 0 ? d + 2 : d + 1);
}