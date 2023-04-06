#include <stdio.h>
#include <algorithm>
using namespace std;

int R, C;
char map[20][21];

char visit[26] = {0,};
int possible(int y, int x) {
  if(y < 0 || y >= R || x < 0 || x >= C) return false;
  int code = map[y][x] - 'A';
  return !visit[code];
}

int dfs(int y, int x) {
  int r = 0;
  int code = map[y][x] - 'A';
  visit[code] = true;
  if(possible(y - 1, x)) r = max(r, dfs(y - 1, x) + 1);
  if(possible(y + 1, x)) r = max(r, dfs(y + 1, x) + 1); 
  if(possible(y, x - 1)) r = max(r, dfs(y, x - 1) + 1); 
  if(possible(y, x + 1)) r = max(r, dfs(y, x + 1) + 1);
  visit[code] = false;
  return r == 0 ? 1 : r;
}

int main() {
  scanf("%d%d", &R, &C);
  for(int i=0; i<R; ++i) scanf("%s", map[i]);
  printf("%d\n", dfs(0, 0));
}
