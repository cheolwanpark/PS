#include <stdio.h>
#include <map>
using namespace std;

typedef unsigned long long llu;

void genSums(int *arr, int N, map<int, llu> &m) {
  for(int i=0; i<N; ++i) {
    for(int j=i+1; j<=N; ++j) {
      int s = arr[j] - arr[i];
      auto iter = m.find(s);
      if(iter != m.end()) iter->second += 1;
      else m[s] = 1;
    }
  }
}

int main() {
  int T, N, M;
  int A[1001]={0,}, B[1001]={0,};
  map<int, llu> Asums, Bsums;
  scanf("%d%d", &T, &N);
  for(int i=1; i<=N; ++i) {
    scanf("%d", A+i);
    A[i] = A[i-1] + A[i];
  }
  scanf("%d", &M);
  for(int i=1; i<=M; ++i) {
    scanf("%d", B+i);
    B[i] = B[i-1] + B[i];
  }

  genSums(A, N, Asums);
  genSums(B, M, Bsums);

  llu r = 0;
  for(auto iter : Asums) {
    auto iter2 = Bsums.find(T - iter.first);
    if(iter2 != Bsums.end()) {
      r += iter.second * iter2->second;
    }
  }
  printf("%llu\n", r);
}