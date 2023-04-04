#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, M;
ll B;
int m[500][500];

ll price(int h) {
  ll rm = 0;
  ll add = 0;
  for(int i=0; i<N; ++i) {
    for(int j=0; j<M; ++j) {
      if(m[i][j] < h) add += h - m[i][j];
      else rm += m[i][j] - h;
    }
  }
  if(rm + B >= add) return rm * 2ll + add;
  else return -1;
}

pair<ll, int> search(int s, int e) {
  ll mn = price(s);
  int mn_h = s;
  for(int i=s+1; i<e; ++i) {
    ll p = price(i);
    if(p < 0) break;
    else if(p <= mn) {
      mn = p;
      mn_h = i;
    }
  }
  return {mn, mn_h};
}

int main() {
  int mn=64000001, mx=0;
  scanf("%d%d%lld", &N, &M, &B);
  for(int i=0; i<N; ++i) {
    for(int j=0; j<M; ++j) {
      scanf("%d", &m[i][j]);
      mn = min(mn, m[i][j]);
      mx = max(mx, m[i][j]);
    }
  }
  auto r = search(mn, mx+1);
  printf("%lld %d\n", r.first, r.second);
}