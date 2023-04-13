#include <stdio.h>
#include <string.h>

int main() {
  char s[101];
  int pos[26];
  scanf("%s", s);
  memset(pos, -1, sizeof(pos));
  for(int i=0; i<strlen(s); ++i) {
    int idx = s[i] - 'a';
    if(pos[idx] < 0) pos[idx] = i;
  }
  for(int i=0; i<26; ++i) printf("%d ", pos[i]);
  printf("\n");
}