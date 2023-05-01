#include <stdio.h>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
int N;
ii x[100000], y[100000], z[100000];
map<int, int> edges[100000];
bool visit[100000]={0};

void updateEdge(int a, int b, int c) {
  auto find = edges[a].find(b);
  if(find != edges[a].end() && find->second > c) find->second = c;
  else edges[a].insert({b, c});
}

int cost(int a, int b) {
  auto find = edges[a].find(b);
  if(find != edges[a].end()) return find->second;
  else return -1;
}

void pushEdges(ii *arr) {
  sort(arr, arr+N);
  for(int i=1; i<N; ++i) {
    auto [ax, a] = arr[i-1];
    auto [bx, b] = arr[i];
    auto d = abs(ax-bx);
    updateEdge(a, b, d);
    updateEdge(b, a, d);
  }
}

int main() {
  scanf("%d", &N);
  for(int i=0; i<N; ++i) {
    scanf("%d%d%d", &x[i].first, &y[i].first, &z[i].first);
    x[i].second = y[i].second = z[i].second = i;
  }
  pushEdges(x);
  pushEdges(y);
  pushEdges(z);

  long long c = 0, cnt=0;
  priority_queue<ii, vector<ii>, greater<ii>> q;
  q.push({0, 0});
  while(!q.empty() && cnt < N) {
    auto [cost, node] = q.top(); q.pop();
    if(visit[node]) continue;
    visit[node] = true;
    cnt++;
    c += cost;
    for(auto edge : edges[node]) {
      if(!visit[edge.first]) q.push({edge.second, edge.first});
    }
  }
  printf("%lld\n", c);
}