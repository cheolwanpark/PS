#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

struct P {int y; int x;};

int T, H, W;
char map[100][101];
char keyInput[27];
bool visit[100][100];
bool key[26];
queue<P> q;
queue<P> doors[26];

void clear() {
  memset(visit, 0, sizeof(visit));
  memset(key, 0, sizeof(key));
  for(int i=0; i<26; ++i) {
    queue<P> empty;
    swap(doors[i], empty);
  }
}

bool isDoor(int y, int x) {
  return 'A' <= map[y][x] && map[y][x] <= 'Z';
}
bool isKey(int y, int x) {
  return 'a' <= map[y][x] && map[y][x] <= 'z';
}

void pushToQ(int y, int x) {
  if(y < 0 || y >= H || x < 0 || x >=W) return;  
  else if(map[y][x] == '*') return;
  else if(visit[y][x]) return;

  if(map[y][x] == '.' || map[y][x] == '$') {
    q.push({y, x});
  } else if(isKey(y, x)) {
    q.push({y, x});
    int code = map[y][x] - 'a';
    key[code] = true;
    while(!doors[code].empty()) {
      q.push(doors[code].front()); doors[code].pop();
    }
  } else if(isDoor(y, x)) {
    int code = map[y][x] - 'A'; 
    if(key[code]) q.push({y, x});
    else doors[code].push({y, x});
  }
  visit[y][x] = true;
}

int main() {
  scanf("%d", &T);
  while(T--) {
    clear();
    scanf("%d%d", &H, &W);
    for(int i=0; i<H; ++i) scanf("%s", map[i]);
    scanf("%s", keyInput);
    if(keyInput[0] != '0') {
      for(size_t i=0; i<strlen(keyInput); ++i) key[keyInput[i] - 'a'] = true;
    }

    for(int i=0; i<H; ++i) {
      pushToQ(i, 0);
      pushToQ(i, W-1);
    }
    for(int i=0; i<W; ++i) {
      pushToQ(0, i);
      pushToQ(H-1, i);
    }

    int docs = 0;
    while(!q.empty()) {
      auto [y, x] = q.front(); q.pop();
      if(map[y][x] == '$') docs++;
      pushToQ(y-1, x);
      pushToQ(y+1, x);
      pushToQ(y, x-1);
      pushToQ(y, x+1);
    }
    printf("%d\n", docs);
  }
}