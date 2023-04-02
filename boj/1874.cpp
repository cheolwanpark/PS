#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int N, n[100000];
  stack<int> s;
  vector<char> ops;
  scanf("%d", &N);
  for(int i=0; i<N; ++i) scanf("%d", n+i);

  int cur = 1;
  int impos = false;
  for(int i=0; i<N; ++i) {
    while(cur <= n[i]) {
      s.push(cur++);
      ops.push_back('+');
    }
    if(s.top() != n[i]) {
      impos = true;
      break;
    }
    s.pop();
    ops.push_back('-');
  }
  if(impos) {
    printf("NO\n");
  } else {
    for(auto op : ops) printf("%c\n", op);
  }
}