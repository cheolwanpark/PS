#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int main() {
  int N, x;
  priority_queue<ii, vector<ii>, greater<ii>> q;
  scanf("%d", &N);
  for(int i=0; i<N; ++i) {
    scanf("%d", &x);
    if(x != 0) {
      q.push({abs(x), x});
    } else if(!q.empty()) {
      printf("%d\n", q.top().second); q.pop();
    } else {
      printf("0\n");
    }
  }
}