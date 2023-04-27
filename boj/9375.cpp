#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
  int T, N;
  char name[21], kind[21];
  scanf("%d", &T);
  while(T--) {
    map<string, int> cnt;
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
      scanf("%s%s", name, kind);
      string k(kind);
      cnt[k]++;
    }

    int r=1;
    for(auto iter : cnt) {
      r *= iter.second + 1;
    }
    printf("%d\n", r - 1);
  }
}