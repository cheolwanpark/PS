#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, M, A, B;
  int indeg[32001]={0};
  vector<int> e[32001];
  priority_queue<int, vector<int>, greater<int>> q;

  scanf("%d%d", &N, &M);
  for(int i=0; i<M; ++i) {
    scanf("%d%d", &A, &B);
    indeg[B]++;
    e[A].push_back(B);
  }

  for(int i=1; i<=N; ++i) {
    if(indeg[i] == 0) q.push(i);
  }
  while(!q.empty()) {
    auto node = q.top(); q.pop();
    printf("%d ", node);
    for(auto next : e[node]) {
      indeg[next]--;
      if(indeg[next] == 0) q.push(next);
    }
  }
}