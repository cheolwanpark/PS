#include <stdio.h>

void postord(int *arr, int N) {
  if(N == 0) return;
  int rt = arr[0], i;
  for(i=1; i<N && arr[i] < rt; ++i);
  postord(arr+1, i-1);
  postord(arr+i, N-i);
  printf("%d\n", rt);
}

int main() {
  int arr[10000], N=0;
  while(scanf("%d", &arr[N]) != EOF) N++;
  postord(arr, N);
}