#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
  int N;
  pair<int, int> p[100000];
  scanf("%d", &N);
  for(int i=0; i<N; ++i) scanf("%d%d", &p[i].second, &p[i].first);
  sort(p, p+N);
  for(int i=0; i<N; ++i) printf("%d %d\n", p[i].second, p[i].first);
}