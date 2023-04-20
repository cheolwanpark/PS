#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, A[1000000], p[1000000];
  vector<int> memo, out;
  scanf("%d", &N);

  for(int i=0; i<N; ++i) {
    scanf("%d", A+i);
    if(memo.empty() || memo.back() < A[i]) {
      memo.push_back(A[i]);
      p[i] = memo.size();
    } else {
      auto iter = lower_bound(memo.begin(), memo.end(), A[i]);
      auto idx = iter - memo.begin();
      memo[idx] = A[i];
      p[i] = idx+1;
    }
  }

  int tgt = memo.size();
  for(int i=N-1; i>=0; --i) {
    if(p[i] == tgt) {
      out.push_back(A[i]);
      tgt--;
    }
  }
  reverse(out.begin(), out.end());

  printf("%ld\n", memo.size());
  for(auto a : out) {
    printf("%d ", a);
  }
  printf("\n");
}