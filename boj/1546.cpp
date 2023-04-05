#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
  int N, M=0, score[1000];
  double sum = 0.0;
  scanf("%d", &N);
  for(int i=0; i<N; ++i) {
    scanf("%d", score+i);
    M = max(M, score[i]);
  }
  for(int i=0; i<N; ++i) {
    sum += 100.0 * (double)score[i] / (double)M;
  }
  printf("%f\n", sum/(double)N);
}