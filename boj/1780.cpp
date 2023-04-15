#include <stdio.h>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> p3;
int N, m[2187][2187]={0};

bool isFilled(int y, int x, int L) {
  int c = m[y][x];
  for(int i=0; i<L; ++i) {
    for(int j=0; j<L; ++j) {
      if(m[y+i][x+j] != c) return false;
    }
  }
  return true;
}

p3 add(p3 &a, p3 &&b) {
  auto [a1, a2, a3] = a; 
  auto [b1, b2, b3] = b;
  return {a1 + b1, a2 + b2, a3 + b3};
}

p3 solve(int y, int x, int L) {
  if(isFilled(y, x, L)) {
    if(m[y][x] == -1) return {1, 0, 0};
    else if(m[y][x] == 0) return {0, 1, 0};
    else return {0, 0, 1};
  }

  int l = L/3;
  p3 r = {0, 0, 0};
  for(int i=0; i<3; ++i) {
    for(int j=0; j<3; ++j) r = add(r, solve(y+i*l, x+j*l, l));
  }
  return r;
}

int main() {
  scanf("%d", &N);
  for(int i=0; i<N; ++i) {
    for(int j=0; j<N; ++j) scanf("%d", &m[i][j]);
  }
  auto [a, b, c] = solve(0, 0, N);
  printf("%d\n%d\n%d\n", a, b, c);
}