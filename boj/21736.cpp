#include <stdio.h>

int N, M, si, sj;
char m[600][601];
bool vst[600][600]={0};

int dfs(int i, int j) {
    if(i < 0 || i >= N || j < 0 || j >= M || m[i][j] == 'X' || vst[i][j]) return 0;
    vst[i][j] = 1;
    int r = m[i][j] == 'P' ? 1 : 0;
    r += dfs(i-1, j);
    r += dfs(i+1, j);
    r += dfs(i, j-1);
    r += dfs(i, j+1);
    return r;
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; ++i) {
        scanf("%s", m[i]);
        for(int j=0; j<M; ++j) {
            if(m[i][j] == 'I') {
                si = i; sj = j;
            }
        }
    }
    int r = dfs(si, sj);
    if(r > 0) printf("%d\n", r);
    else printf("TT\n");
}