#include <stdio.h>
#include <algorithm>
using namespace std;

int memo[100001];

int find(int g) {
  if(memo[g] == g) return g;
  else return memo[g] = find(memo[g]);
}

int set(int g) {
  int p = find(g);
  if(p == 0) return 0;
  memo[p] = find(p-1);
  return p;
}

int main() {
  int G, P, g;
  scanf("%d%d", &G, &P);
  for(int i=1; i<=G; ++i) memo[i] = i;
  int r = P;
  for(int i=1; i<=P; ++i) {
    scanf("%d", &g);
    if(set(g) == 0) {
      r = min(r, i-1);
      break;
    }
  }
  printf("%d\n", r);
}