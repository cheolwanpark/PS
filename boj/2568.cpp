#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
  int N, p[100000];
  ii l[100000];
  scanf("%d",  &N);
  for(int i=0; i<N; ++i) scanf("%d%d", &l[i].first, &l[i].second);
  sort(l, l+N);

  vector<int> memo;
  for(int i=0; i<N; ++i) {
    auto [a, b] = l[i];
    if(memo.empty() || memo.back() < b) {
      memo.push_back(b);
      p[i] = memo.size();
    } else {
      auto iter = lower_bound(memo.begin(), memo.end(), b);
      *iter = b;
      p[i] = (iter - memo.begin()) + 1;
    }
  }

  int tgt = memo.size();
  stack<int> s;
  for(int i=N-1; i>=0; --i) {
    if(p[i] == tgt) {
      s.push(i);
      tgt--;
    }
  }

  printf("%d\n", N - s.size());
  for(int i=0; i<N; ++i) {
    if(s.empty() || i != s.top()) printf("%d\n", l[i].first);
    else s.pop();
  }
}