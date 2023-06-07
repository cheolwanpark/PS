#include <stdio.h>
#include <queue>
using namespace std;

int N, M, m[1000][1000], si, sj;
queue<pair<int, int>> q;

void push(int i, int j, int c) {
    if(0 <= i && i < N && 0 <= j && j < M && m[i][j] > 0) {
        m[i][j] = -c;
        q.push({i, j});
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            scanf("%d", &m[i][j]);
            if(m[i][j] == 2) {
                si = i; sj = j;
            }
        }
    }
    push(si, sj, 0);
    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        int c = -m[i][j];
        push(i-1, j, c+1);
        push(i+1, j, c+1);
        push(i, j-1, c+1);
        push(i, j+1, c+1);
    }
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) printf("%d ", m[i][j] > 0 ? -1 : -m[i][j]);
        printf("\n");
    }
}