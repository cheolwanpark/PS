#include <stdio.h>
#include <string.h>

int T, N;
int sel[100001];
int visit[100001];

int getNumCycleNodes(int start) {
  auto node = start;
  while(!visit[node]) {
    visit[node] = start;
    node = sel[node];
  }
  if(visit[node] != start) return 0;

  int s=node, n=1;
  while(sel[node] != s) {
    node = sel[node];
    n++;
  }
  return n;
}

int main() {
  scanf("%d", &T);
  while(T--) {
    int cnt = 0;
    scanf("%d", &N);
    for(int i=1; i<=N; ++i) {
      scanf("%d", sel+i);
      visit[i] = 0;
    }
    for(int i=1; i<=N; ++i) {
      if(!visit[i]) {
        cnt += getNumCycleNodes(i);
      }
    }
    printf("%d\n", N - cnt);
  }
}