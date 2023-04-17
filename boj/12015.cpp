#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, n;
  vector<int> memo={0};
  scanf("%d", &N);
  for(int i=0; i<N; ++i) {
    scanf("%d", &n);
    if(memo.back() < n) {
      memo.push_back(n);
    } else {
      auto iter = lower_bound(memo.begin(), memo.end(), n);
      *iter = n;
    }
  }
  printf("%ld\n", memo.size() - 1);
}