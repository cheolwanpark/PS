#include <stdio.h>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;

typedef pair<float, int> edge;

int main() {
  int N;
  pair<float, float> stars[100];
  vector<edge> edges[100];
  scanf("%d", &N);
  for(int i=0; i<N; ++i) scanf("%f%f", &stars[i].first, &stars[i].second);
  for(int i=0; i<N; ++i) {
    for(int j=i+1; j<N; ++j) {
      auto [x1, y1] = stars[i];
      auto [x2, y2] = stars[j];
      auto dx = x2 - x1, dy = y2 - y1;
      auto d = sqrt(dx*dx + dy*dy);
      edges[i].push_back({d, j});
      edges[j].push_back({d, i});
    }
  }

  priority_queue<edge, vector<edge>, greater<edge>> q;
  bool visit[100]={0};
  q.push({0, 0});
  float r = 0.0;
  while(!q.empty()) {
    auto [cost, node] = q.top(); q.pop();
    if(visit[node]) continue;
    visit[node] = true;
    r += cost;
    for(auto edge : edges[node]) {
      auto [d, n] = edge;
      if(!visit[n]) q.push(edge);
    }
  }

  printf("%f\n", r);
}