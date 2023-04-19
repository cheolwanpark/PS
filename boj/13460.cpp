#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

const int INF = 987654321;

int M, N;

int isValid(int y, int x) {
  return y >= 0 && y < M && x >= 0 && x < N;
}

int exists(char b[10][11], char c) {
  for(int i=0; i<M; ++i) {
    for(int j=0; j<N; ++j) {
      if(b[i][j] == c) return true;
    }
  }
  return false;
}

void moveBall(char b[10][11], int y, int x, int dy, int dx) {
  int ny, nx;
  while(true) {
    ny = y + dy;
    nx = x + dx;
    if(!isValid(ny, nx) || (b[ny][nx] != '.' && b[ny][nx] != 'O')) 
      break;
    else if(b[ny][nx] == 'O') {
      b[y][x] = '.';
      break;
    }
    b[ny][nx] = b[y][x];
    b[y][x] = '.';
    y = ny; x = nx;
  }
}

void moveV(char b[10][11], int d) {
  for(int j=0; j<N; ++j) {
    for(int i=0; i<M; ++i) {
      auto y = d > 0 ? M-1-i : i;
      auto x = j;
      if(b[y][x] == 'R' || b[y][x] == 'B') {
        moveBall(b, y, x, d, 0);
      }
    }
  }
}

void moveH(char b[10][11], int d) {
  for(int i=0; i<M; ++i) {
    for(int j=0; j<N; ++j) {
      auto y = i;
      auto x = d > 0 ? N-1-j : j;
      if(b[y][x] == 'R' || b[y][x] == 'B') {
        moveBall(b, y, x, 0, d);
      }
    }
  }
}

int solve(char b[10][11], int depth) {
  if(depth > 10) return INF;
  else if(!exists(b, 'B')) return INF;
  else if(!exists(b, 'R')) return depth;
  
  char tmp[10][11];
  int r = INF;

  memcpy(tmp, b, sizeof(tmp));
  moveV(tmp, -1);
  r = min(r, solve(tmp, depth + 1));

  memcpy(tmp, b, sizeof(tmp));
  moveV(tmp, 1);
  r = min(r, solve(tmp, depth + 1));

  memcpy(tmp, b, sizeof(tmp));
  moveH(tmp, -1);
  r = min(r, solve(tmp, depth + 1));

  memcpy(tmp, b, sizeof(tmp));
  moveH(tmp, 1);
  r = min(r, solve(tmp, depth + 1));
  
  return r;
}

int main() {
  char b[10][11]={0};
  scanf("%d%d", &M, &N);
  for(int i=0; i<M; ++i) scanf("%s", b[i]);

  auto r = solve(b, 0);
  printf("%d\n", r == INF ? -1 : r);
}