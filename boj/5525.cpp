#include <stdio.h>

int N, M;
char s[1000001];

int main() {
  scanf("%d%d", &N, &M);
  scanf("%s", s);
  
  int r = 0, cnt=0;
  for(int i=0; i<M-2;) {
    if(s[i] == 'I' && s[i+1] == 'O' && s[i+2] == 'I') {
      cnt++;
      i += 2;
      if(cnt >= N) r++;
    } else {
      cnt=0;
      ++i;
    }
  }
  printf("%d\n", r);
}