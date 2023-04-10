#include <stdio.h>
#include <stack>
using namespace std;

int conv(int N) {
  stack<int> s;
  int digits=0, r=0, p=1;
  while(N > 0) {
    s.push(N%10);
    ++digits;
    N /= 10;
  }
  for(int d=0; d<digits; ++d, p*=10) {
    r += p*s.top(); s.pop();
  }
  return r;
}

int main() {
  int A, B;
  scanf("%d%d", &A, &B);
  A = conv(A);
  B = conv(B);
  printf("%d\n", A > B ? A : B);
}