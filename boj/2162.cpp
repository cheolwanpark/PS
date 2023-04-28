#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, p> seg;

int ccw(p a, p b, p c) {
  auto s1 = a.first*b.second + b.first*c.second + c.first*a.second,
       s2 = a.second*b.first + b.second*c.first + c.second*a.first;
  auto v = s1 - s2;
  return v == 0 ? 0 : (v > 0 ? 1 : -1);
}

bool intersect(seg s1, seg s2) {
  auto [a, b] = s1;
  auto [c, d] = s2;
  auto ab = ccw(a, b, c) * ccw(a, b, d);
  auto cd = ccw(c, d, a) * ccw(c, d, b);

  if(ab == 0 && cd == 0) {
    return c <= b && a <= d;
  } else {
    return ab <= 0 && cd <= 0;
  }
}

int N, x1, y1, x2, y2;
seg s[3000];
bool visit[3000];
vector<int> edges[3000];

int dfs(int node) {
  visit[node] = true;
  int r = 1;
  for(auto nxt : edges[node]) {
    if(!visit[nxt]) r += dfs(nxt);
  }
  return r;
}

int main() {
  scanf("%d", &N);
  for(int i=0; i<N; ++i) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    s[i] = {{x1, y1}, {x2, y2}};
    if(s[i].first > s[i].second) swap(s[i].first, s[i].second);
  }

  for(int i=0; i<N; ++i) {
    for(int j=i+1; j<N; ++j) {
      if(intersect(s[i], s[j])) {
        edges[i].push_back(j);
        edges[j].push_back(i);
      }
    }
  }

  int groups = 0;
  int mx = 0;
  for(int i=0; i<N; ++i) {
    if(!visit[i]) {
      groups++;
      mx = max(mx, dfs(i));
    }
  }
  printf("%d\n%d\n", groups, mx);
}

