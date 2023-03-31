// https://www.acmicpc.net/problem/11660
#include <stdio.h>

int N, M;
int tbl[1025][1025];
int memo[1025][1025];

int main() {
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) scanf("%d", &tbl[i][j]);
    }
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            memo[i][j] = memo[i-1][j] + memo[i][j-1] - memo[i-1][j-1] + tbl[i][j];
        }
    }


    int x1, y1, x2, y2;
    for(int i=0; i<M; ++i) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1 = x1 - 1; y1 = y1 - 1;
        printf("%d\n", memo[x2][y2] - (memo[x1][y2] + memo[x2][y1] - memo[x1][y1]));
    }
}