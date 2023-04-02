#include <stdio.h>
#include <utility>
using namespace std;

int main() {
  int N;
  pair<int, int> p[50];
  scanf("%d", &N);
  for(int i=0; i<N; ++i) scanf("%d%d", &p[i].first, &p[i].second);
  for(int i=0; i<N; ++i) {
    int k = 0;
    for(int j=0; j<N; ++j) {
      if(p[i].first < p[j].first && p[i].second < p[j].second) ++k;
    }
    printf("%d ", k+1);
  }
  printf("\n");
}