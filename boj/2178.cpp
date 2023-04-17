#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

int N, M;
char m[100][101];
bool visit[100][100]={0};
queue<tuple<int, int, int>> q;

void pushToQ(int y, int x, int l) {
  if(y < 0 || y >= N || x < 0 || x >= M) return;
  else if(m[y][x] == '0') return;
  else if(visit[y][x]) return;

  q.push({y, x, l});
  visit[y][x] = true;
}

int main() {
  scanf("%d%d", &N, &M);
  for(int i=0; i<N; ++i) {
    scanf("%s", m[i]);
  }
  pushToQ(0, 0, 1);
  while(!q.empty()) {
    auto [y, x, l] = q.front(); q.pop();
    if(y == N-1 && x == M-1) {
      printf("%d\n", l);
      break;
    }
    pushToQ(y-1, x, l+1);
    pushToQ(y+1, x, l+1);
    pushToQ(y, x-1, l+1);
    pushToQ(y, x+1, l+1);
  }
}