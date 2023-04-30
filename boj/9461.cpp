#include <stdio.h>

int main() {
  int T, N;
  long long memo[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};
  for(int i=11; i<=100; ++i) {
    memo[i] = memo[i-1] + memo[i-5];
  }
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &N);
    printf("%ld\n", memo[N]);
  }
}