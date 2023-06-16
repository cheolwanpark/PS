#include <stdio.h>

int N, m[16][16], r[16][16][3]={0}, y=0, x=1, s=0;
int valid(int i, int j) {
    if(i < 0 || i >=N || j < 0 || j >= N) return false;
    return m[i][j] == 0;
}
int main() {
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) scanf("%d", &m[i][j]);
    }
    r[y][x][s] = 1;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            if(!valid(i, j)) continue;
            if(valid(i, j-1)) r[i][j][0] += r[i][j-1][0] + r[i][j-1][2];
            if(valid(i-1, j) && valid(i, j-1) && valid(i-1, j-1)) r[i][j][2] += r[i-1][j-1][0] + r[i-1][j-1][1] + r[i-1][j-1][2];
            if(valid(i-1, j)) r[i][j][1] += r[i-1][j][1] + r[i-1][j][2];
        }
    }
    printf("%d\n", r[N-1][N-1][0] + r[N-1][N-1][1] + r[N-1][N-1][2]);
}