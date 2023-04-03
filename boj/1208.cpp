#include <stdio.h>
#include <map>
using namespace std;

typedef unsigned long long llu;

int N, S;
int n[40];

void genSumMap(int *arr, int i, int len, int sum, map<int, llu> &m) {
  if(i == len) 
    m[sum]++;
  else {
    genSumMap(arr, i+1, len, sum + arr[i], m);
    genSumMap(arr, i+1, len, sum, m);
  }
} 

int main() {
  scanf("%d%d", &N, &S);
  for(int i=0; i<N; ++i) scanf("%d", n+i);

  int halfLen = N/2;
  map<int, llu> left, right;
  genSumMap(n, 0, halfLen, 0, left);
  genSumMap(n+halfLen, 0, N-halfLen, 0, right);

  llu cnt = 0;
  for(auto iter : left) {
    cnt += iter.second * right[S - iter.first];
  }
  if(S == 0) --cnt; //emptyset
  printf("%llu\n", cnt);
}