#include <stdio.h>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

const int MOD = 10000;

queue<int> q;
pair<int, char> memo[MOD];

int l(int n) {
  int d4=n%10, d3=(n/10)%10, d2=(n/100)%10, d1=n/1000;
  return d2*1000 + d3*100 + d4*10 + d1;
}

int r(int n) {
  int d4=n%10, d3=(n/10)%10, d2=(n/100)%10, d1=n/1000;
  return d4*1000 + d1*100 + d2*10 + d3;
}

void push(int n, int bef, int cmd) {
  if(memo[n].first < 0) {
    q.push(n);
    memo[n] = {bef, cmd};
  }
}

void print(int n) {
  auto [bef, cmd] = memo[n];
  if(bef == n) return;
  print(bef);
  printf("%c", cmd);
}

int main() {
  int T, A, B;
  scanf("%d", &T);
  while(T--) {
    while(!q.empty()) q.pop();
    for(int i=0; i<MOD; ++i) memo[i] = {-1, 0};

    scanf("%d%d", &A, &B);
    q.push(A);
    memo[A] = {A, 0};
    while(!q.empty()) {
      auto n = q.front(); q.pop();
      if(n == B) {
        print(n); printf("\n");
        break;
      }
      push((n*2)%MOD, n, 'D');
      push((n-1+MOD)%MOD, n, 'S');
      push(l(n), n, 'L');
      push(r(n), n, 'R');
    }
  }
}