#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
 
void moveH(int b[20][20], int N, int d) {
  for(int i=0; i<N; ++i) {
    vector<int> blocks;
    for(int j=0; j<N; ++j) {
      if(d > 0 && b[i][N-1-j] != 0) blocks.push_back(b[i][N-1-j]);
      else if(d < 0 && b[i][j] != 0) blocks.push_back(b[i][j]);
    }
    for(int j=0; j<(int)blocks.size() - 1; ++j) {
      if(blocks[j] == blocks[j+1]) {
        blocks[j] *= 2;
        blocks[j+1] = 0;
      }
    }
    size_t k=0;
    for(int j=0; j<N; ++j) {
      while(k < blocks.size() && blocks[k] == 0) k++;
      auto val = k < blocks.size() ? blocks[k++] : 0;
      if(d > 0) b[i][N-1-j] = val;
      else b[i][j] = val;
    }
  }
}

void moveV(int b[20][20], int N, int d) {
  for(int i=0; i<N; ++i) {
    vector<int> blocks;
    for(int j=0; j<N; ++j) {
      if(d > 0 && b[N-1-j][i] != 0) blocks.push_back(b[N-1-j][i]);
      else if(d < 0 && b[j][i] != 0) blocks.push_back(b[j][i]);
    }
    for(int j=0; j<(int)blocks.size() - 1; ++j) {
      if(blocks[j] == blocks[j+1]) {
        blocks[j] *= 2;
        blocks[j+1] = 0;
      }
    }
    size_t k=0;
    for(int j=0; j<N; ++j) {
      while(k < blocks.size() && blocks[k] == 0) k++;
      auto val = k < blocks.size() ? blocks[k++] : 0;
      if(d > 0) b[N-1-j][i] = val;
      else b[j][i] = val;
    }
  }
}

int maxInBoard(int b[20][20], int N) {
  int r = 0;
  for(int i=0; i<N; ++i) {
    for(int j=0; j<N; ++j) r = max(r, b[i][j]);
  }
  return r;
}

int solve(int b[20][20], int N, int depth) {
  if(depth == 5) return maxInBoard(b, N);

  int r = 0;
  int ub[20][20];

  memcpy(ub, b, sizeof(ub));
  moveH(ub, N, 1);
  r = max(r, solve(ub, N, depth + 1));

  memcpy(ub, b, sizeof(ub));
  moveH(ub, N, -1);
  r = max(r, solve(ub, N, depth + 1));

  memcpy(ub, b, sizeof(ub));
  moveV(ub, N, 1);
  r = max(r, solve(ub, N, depth + 1));

  memcpy(ub, b, sizeof(ub));
  moveV(ub, N, -1);
  r = max(r, solve(ub, N, depth + 1));

  return r;
}

int main() {
  int N;
  int b[20][20];
  scanf("%d", &N);
  for(int i=0; i<N; ++i) {
    for(int j=0; j<N; ++j) scanf("%d", &b[i][j]);
  }

  printf("%d\n", solve(b, N, 0));
}