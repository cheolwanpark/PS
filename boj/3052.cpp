#include <stdio.h>
#include <set>
using namespace std;

int main() {
  int N;
  set<int> s;
  for(int i=0; i<10; ++i) {
    scanf("%d", &N);
    s.insert(N%42);
  }
  printf("%ld\n", s.size());
}