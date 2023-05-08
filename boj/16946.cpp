#include <stdio.h>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
int N, M, memo[1000][1001]={0};
char m[1000][1001];
bool visit[1000][1001];
ii delta[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M;
}

void bfs(int si, int sj) {
    queue<ii> q, wall;
    int cnt = 0;
    q.push({si, sj}); visit[si][sj] = true;
    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        cnt++;
        for(int k=0; k<4; ++k) {
            auto [di, dj] = delta[k];
            auto ni = i+di, nj = j+dj;
            if(isValid(ni, nj) && !visit[ni][nj]) {
                if(m[ni][nj] == '0') q.push({ni, nj});
                else wall.push({ni, nj});
                visit[ni][nj] = true;
            }
        }
    }
    while(!wall.empty()) {
        auto [i, j] = wall.front(); wall.pop();
        memo[i][j] += cnt;
        visit[i][j] = false;
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; ++i) scanf("%s", m[i]);

    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            if(m[i][j] == '0' && !visit[i][j]) bfs(i, j);
        }
    }
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            if(m[i][j] == '1') {
                printf("%d", (memo[i][j]+1)%10);
            } else printf("0");
        }
        printf("\n");
    }
}