#include <stdio.h>
#include <queue>
#include <tuple>
using namespace std;

int N, M, H;
int b[100][100][100];
bool v[100][100][100]={0};
queue<tuple<int, int, int, int>> q;

void pushToQ(int i, int j, int k, int c) {
  if(i < 0 || i >= H || j < 0 || j >= N || k < 0 || k >= M) return;
  else if(v[i][j][k]) return;
  else if(b[i][j][k] == -1) return;
  
  q.push({i, j, k, c});
  v[i][j][k] = true;
}

int main() {
  scanf("%d%d%d", &M, &N, &H);
  int total=0, mature=0;
  for(int i=0; i<H; ++i) {
    for(int j=0; j<N; ++j) {
      for(int k=0; k<M; ++k) {
        scanf("%d", &b[i][j][k]);
        if(b[i][j][k] != -1) total++;
        if(b[i][j][k] == 1) pushToQ(i, j, k, 0);
      }
    }
  }

  int ans=-1;
  while(!q.empty()) {
    auto [i, j, k, c] = q.front(); q.pop();
    mature++;
    if(total == mature) {
      ans = c;
      break;
    }

    pushToQ(i+1, j, k, c+1);
    pushToQ(i-1, j, k, c+1);
    pushToQ(i, j+1, k, c+1);
    pushToQ(i, j-1, k, c+1);
    pushToQ(i, j, k+1, c+1);
    pushToQ(i, j, k-1, c+1);
  }
  printf("%d\n", ans);
}