// https://www.acmicpc.net/problem/2206
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
    int y;
    int x;
    int brk;
    int dist;
};
int N, M;
char visit[1001][1001];
char visit2[1001][1001];
char map[1001][1002];
void push_node(queue<node> &q, int y, int x, int brk, int dist) {
    if(y < 1 || x < 1 || y > N || x > M) return;
    if(!brk && visit[y][x]) return;
    if(brk && visit2[y][x]) return;
    if(map[y][x] == '1' && brk == 0) {
        q.push({y, x, 1, dist});
        visit2[y][x] = true;
    } else if(map[y][x] == '0') {
        q.push({y, x, brk, dist});
        if(brk) visit2[y][x] = true;
        else visit[y][x] = true;
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; ++i) {
        scanf("%s", map[i] + 1);
    }
    
    queue<node> q;
    q.push({1, 1, 0, 1});
    int res = -1;
    while(!q.empty()) {
        auto n = q.front(); q.pop();
        if(n.y == N && n.x == M) {
            res = n.dist;
            break;
        }
        push_node(q, n.y+1, n.x, n.brk, n.dist + 1);
        push_node(q, n.y, n.x+1, n.brk, n.dist + 1);
        push_node(q, n.y-1, n.x, n.brk, n.dist + 1);
        push_node(q, n.y, n.x-1, n.brk, n.dist + 1);
    }
    printf("%d\n", res);
}