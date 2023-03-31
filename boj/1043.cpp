// https://www.acmicpc.net/problem/1043
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int N, M, n, p;
  int visit[51] = {0,};
  int mark[50] = {0,};
  vector<int> partyMembers[50];
  vector<int> joiningParties[51];
  queue<int> q;
  scanf("%d%d", &N, &M);
  scanf("%d", &n);
  for(int i=0; i<n; ++i) {
    scanf("%d", &p);
    q.push(p);
  }
  for(int i=0; i<M; ++i) {
    scanf("%d", &n);
    for(int j=0; j<n; ++j) {
      scanf("%d", &p);
      partyMembers[i].push_back(p);
      joiningParties[p].push_back(i);
    }
  }

  while(!q.empty()) {
    auto cur = q.front(); q.pop();
    for(auto party : joiningParties[cur]) {
      if(!mark[party]) {
        mark[party] = true;
        for(auto m : partyMembers[party]) {
          if(!visit[m]) {
            visit[m] = true;
            q.push(m);
          }
        }
      }
    }
  }

  int r = 0;
  for(int i=0; i<M; ++i) {
    if(!mark[i]) ++r;
  }
  printf("%d\n", r);
}