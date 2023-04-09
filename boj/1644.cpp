#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long llu;

int main() {
  llu N, s = 0;
  vector<llu> psum = {0};
  bool isComp[4000001] = {0};
  scanf("%llu", &N);
  for(llu i=2; i<=N; ++i) {
    if(!isComp[i]) {
      s += i;
      psum.push_back(s);\
      for(llu j=i*2; j<=N; j += i) isComp[j] = true;
    }
  }

  int r = 0;
  for(int j=psum.size() - 1; psum[j] >= N; --j) {
    int exists = binary_search(psum.begin(), psum.end(), psum[j] - N);
    r += exists ? 1 : 0;
  }
  printf("%d\n", r);
}