#include <stdio.h>

int main() {
  int M, N;
  char isComp[1000001] = {0,};
  scanf("%d%d", &M, &N);

  isComp[0] = isComp[1] = true;
  for(int i=2; i<=N; ++i) {
    if(!isComp[i]) {
      for(int j=i*2; j<=N; j += i) isComp[j] = true;
      if(i >= M) printf("%d\n", i);
    }
  }
}