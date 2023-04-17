#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
pair<int, int> m[500];
int memo[500][500]={0};

int main() {
  scanf("%d", &N);
  for(int i=0; i<N; ++i) scanf("%d%d", &m[i].first, &m[i].second);
  for(int l=1; l<N; ++l) {
    for(int j=0; j+l<N; ++j) {
      int lft = j, rgt = j+l;
      memo[lft][rgt] = 2147483647;
      for(int k=lft; k<=rgt; ++k) {
        memo[lft][rgt] = min(
          memo[lft][rgt], 
          memo[lft][k] + memo[k+1][rgt] + m[lft].first * m[k].second * m[rgt].second
        );
      }
    }
  }
  printf("%d\n", memo[0][N-1]);
}