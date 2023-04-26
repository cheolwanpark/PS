#include <stdio.h>
#include <algorithm>
using namespace std;

int N, board[10][10];
pair<int, int> bs[100];

bool possible(int y, int x, int c) {
  if(board[y][x] == 0) return false;
  for(int i=0; i<c; ++i) {
    auto [by, bx] = bs[i];
    if(abs(by - y) == abs(bx - x)) return false;
  }
  return true;
}

int solve(int y, int x, int c, int col) {
  int r = c;
  for(int i=y; i<N; ++i) {
    int sx = i == y ? x : 0;
    for(int j=sx; j<N; ++j) {
      if(possible(i, j, c) && (i + j)%2 == col) {
        bs[c] = {i, j};
        r = max(r, solve(i, j, c+1, col));
      }
    }
  }
  return r;
}

int main() {
  scanf("%d", &N);
  for(int i=0; i<N; ++i) {
    for(int j=0; j<N; ++j) scanf("%d", &board[i][j]);
  }
  printf("%d\n", solve(0, 0, 0, 0) + solve(0, 0, 0, 1));
}