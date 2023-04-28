#include <stdio.h>
#include <string.h>

int N;
char b[100][101];
bool visit1[100][100]={0}, visit2[100][100]={0};

void dfs1(int y, int x, char col) {
  if(y < 0 || y >= N || x < 0 || x >= N) return;
  if(visit1[y][x]) return;
  if(b[y][x] != col) return;
  visit1[y][x] = true;
  dfs1(y-1, x, col); dfs1(y+1, x, col);
  dfs1(y, x-1, col); dfs1(y, x+1, col);
}

void dfs2(int y, int x, char col) {
  if(y < 0 || y >= N || x < 0 || x >= N) return;
  if(visit2[y][x]) return;
  if(b[y][x] != col && (col == 'B' || b[y][x] == 'B')) return;
  visit2[y][x] = true;
  dfs2(y-1, x, col); dfs2(y+1, x, col);
  dfs2(y, x-1, col); dfs2(y, x+1, col);
}

int main() {
  scanf("%d", &N);
  for(int i=0; i<N; ++i) scanf("%s", b[i]);
  int r1=0, r2=0;
  for(int i=0; i<N; ++i) {
    for(int j=0; j<N; ++j) {
      if(!visit1[i][j]) {
        r1++;
        dfs1(i, j, b[i][j]);
      }
      if(!visit2[i][j]) {
        r2++;
        dfs2(i, j, b[i][j]);
      }
    }
  }
  printf("%d %d\n", r1, r2);
}