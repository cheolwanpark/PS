#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int N, M, E, pre, nxt;
vector<int> e[1001];
int order[1001]={0};

int main() {
  scanf("%d%d", &N, &M);
  for(int i=0; i<M; ++i) {
    scanf("%d", &E);
    scanf("%d", &pre);
    for(int j=1; j<E; ++j) {
      scanf("%d", &nxt);
      e[pre].push_back(nxt);
      order[nxt]++;
      pre = nxt;
    }
  }

  queue<int> q;
  queue<int> out;
  int visit = 0;
  for(int i=1; i<=N; ++i) {
    if(order[i] == 0) q.push(i);
  }
  while(!q.empty()) {
    auto node = q.front(); q.pop(); visit++;
    out.push(node);
    for(auto n : e[node]) {
      order[n]--;
      if(order[n] == 0) q.push(n);
    }
  }
  if(visit != N) printf("0\n");
  else {
    while(!out.empty()) {
      printf("%d\n", out.front());
      out.pop();
    }
  }
}