#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

typedef pair<int, int> ii;
int N, M, m[100][100], cnt=0, r=0;
bool vst[100][100];

void push(queue<ii> &q, int i, int j) {
    if(0 <= i && i < N && 0 <= j && j < M && !vst[i][j]) {
        q.push({i, j});
        vst[i][j] = true;
    }
}
int isAir(int i, int j) {
    return m[i][j] == 0 && vst[i][j] ? 1 : 0;
}
int bfs() {
    queue<ii> q;
    queue<ii> c;
    q.push({0, 0}); vst[0][0] = 1;
    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        if(m[i][j] == 1) {
            c.push({i, j});
            continue;
        }
        push(q, i-1, j);
        push(q, i+1, j);
        push(q, i, j-1);
        push(q, i, j+1);
    }

    int r = 0;
    while(!c.empty()) {
        auto [i, j] = c.front(); c.pop();
        if(isAir(i-1, j) + isAir(i+1, j) + isAir(i, j-1) + isAir(i, j+1) >= 2) q.push({i, j});
    }
    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        m[i][j] = 0;
        r++;
    }
    return r;
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            scanf("%d", &m[i][j]);
            cnt += m[i][j];
        }
    }

    while(cnt > 0) {
        memset(vst, 0, sizeof(vst));
        cnt -= bfs();
        r++;
    }
    printf("%d\n", r);
}