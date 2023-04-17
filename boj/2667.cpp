#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N;
char m[25][26];
bool visit[25][25]={0};
vector<int> sizes;

int count(int y, int x) {
  if(y < 0 || y >= N || x < 0 || x >= N) return 0;
  else if(visit[y][x]) return 0;
  else if(m[y][x] == '0') return 0;
  visit[y][x] = true;
  int r = 1;
  r += count(y-1, x);
  r += count(y+1, x);
  r += count(y, x-1);
  r += count(y, x+1);
  return r;
}

int main() {
  scanf("%d", &N);
  for(int i=0; i<N; ++i) scanf("%s", m[i]);
  for(int y=0; y<N; ++y) {
    for(int x=0; x<N; ++x) {
      if(!visit[y][x] && m[y][x] == '1') sizes.push_back(count(y, x));
    }
  }
  sort(sizes.begin(), sizes.end());
  printf("%ld\n", sizes.size());
  for(auto size : sizes) printf("%d\n", size);
}