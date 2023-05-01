#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
  int N, pos[100][100]={0};
  scanf("%d", &N);
  for(int i=0; i<N; ++i) {
    for(int j=0; j<N; ++j) scanf("%d", &pos[i][j]);
  }
  for(int k=0; k<N; ++k) {
    for(int i=0; i<N; ++i) {
      for(int j=0; j<N; ++j) {
        if(pos[i][k] && pos[k][j]) pos[i][j] = 1;
      }
    }
  }
  for(int i=0; i<N; ++i) {
    for(int j=0; j<N; ++j) printf("%d ", pos[i][j]);
    printf("\n");
  }
}