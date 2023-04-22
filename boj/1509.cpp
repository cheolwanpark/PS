#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int main() {
  int L, memo[2500];
  char s[2501];
  bool P[2500][2500]={false};
  scanf("%s", s); L = strlen(s);

  for(int i=0; i<L; ++i) {
    P[i][i] = true;
    if(i+1 < L && s[i] == s[i+1]) P[i][i+1] = true;
  }
  for(int l=3; l<=L; ++l) {
    for(int i=0; i<L-l+1; ++i) {
      int j = i+l-1;
      P[i][j] = P[i+1][j-1] && s[i] == s[j];
    }
  }
  for(int i=0; i<L; ++i) {
    memo[i] = P[0][i] ? 1 : INF;
    for(int j=0; j<i; ++j) {
      if(P[j+1][i]) memo[i] = min(memo[i], memo[j] + 1);
    }
  }
  printf("%d\n", memo[L-1]);
}