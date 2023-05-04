#include <stdio.h>
#include <map>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const int e[8][8] = {
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 0, 0},
  {0, 1, 1, 0, 1, 1, 0, 0},
  {0, 0, 1, 1, 0, 1, 0, 1},
  {0, 0, 0, 1, 1, 0, 1, 0},
  {0, 0, 0, 0, 0, 1, 0, 1},
  {0, 0, 0, 0, 1, 0, 1, 0},
};

map<int, ll> memo[8][8];
ll solve(int from, int to, int D) {
  if(D == 1) return e[from][to];

  auto iter = memo[from][to].find(D);
  if(iter != memo[from][to].end()) return iter->second;

  ll r = 0;
  int D1 = D / 2, D2 = D - D1;
  for(int i=0; i<8; ++i) {
    r = (r + solve(from, i, D1)*solve(i, to, D2)) % MOD;
  }
  memo[from][to][D] = r;
  return r;
}

int main() {
  int D;
  scanf("%d", &D);
  printf("%lld\n", solve(0, 0, D));
}