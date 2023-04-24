#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
  int N, M, a, b, c;
  vector<ii> e[100001];
  scanf("%d%d", &N, &M);
  for(int i=0; i<M; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    e[a].push_back({c, b});
    e[b].push_back({c, a});
  }

  priority_queue<ii, vector<ii>, greater<ii>> q;
  int cnt=1, mx=0, sum=0;
  bool visit[100001]={0};

  visit[1] = true;
  for(auto edg : e[1]) {
    q.push(edg);
  }

  while(cnt < N) {
    auto [c, n] = q.top(); q.pop();
    if(visit[n]) continue;

    visit[n] = true;
    cnt++;
    sum += c;
    mx = max(mx, c);

    for(auto edg : e[n]) {
      auto [c, n] = edg;
      if(!visit[n]) q.push(edg);
    }
  }

  printf("%d\n", sum - mx);
}