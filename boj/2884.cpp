#include <stdio.h>

int main() {
  int H, M;
  scanf("%d%d", &H, &M);
  if(M < 45) {
    H = (H + 24 - 1) % 24;
  }
  M = (M + 60 - 45) % 60;
  printf("%d %d\n", H, M);
}