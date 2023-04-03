#include <stdio.h>
#include <stack>
using namespace std;

int main() {
  int K, n, sum=0;
  stack<int> s;
  scanf("%d", &K);
  for(int i=0; i<K; ++i) {
    scanf("%d", &n);
    if(n != 0) {
      sum += n;
      s.push(n);
    } else {
      sum -= s.top();
      s.pop();
    }
  }
  printf("%d\n", sum);
}