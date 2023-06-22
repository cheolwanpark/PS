#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int valid(char *p, int bef, int cur, int M) {
    for(int i=0; i<M; ++i) {
        if(cur & (1<<i)) {
            if(p[i] == 'x') return false;
            if(i > 0 && (bef & (1<<(i-1)) || cur & (1<<(i-1)))) return false;
            if(i < M-1 && (bef & (1<<(i+1)) || cur & (1<<(i+1)))) return false;
        }
    }
    return true;
}

int count(int m, int M) {
    int r = 0;
    for(int i=0; i<M; ++i) r += (m & (1<<i)) ? 1 : 0;
    return r;
}

int main() {
    int C;
    scanf("%d", &C);
    while(C--) {
        int N, M, r=0, memo[10][1024], maskN;
        char p[10][11];
        scanf("%d%d", &N, &M);
        maskN = 1 << M;
        for(int i=0; i<N; ++i) scanf("%s", p[i]);
        for(int m=0; m<maskN; ++m) {
            memo[0][m] = valid(p[0], 0, m, M) ? count(m, M) : 0;
        }
        for(int i=1; i<N; ++i) {
            for(int cur=0; cur<maskN; ++cur) {
                memo[i][cur] = 0;
                for(int bef=0; bef<maskN; ++bef) {
                    if(valid(p[i], bef, cur, M)) memo[i][cur] = max(memo[i][cur], memo[i-1][bef] + count(cur, M));
                }
            }
        }
        for(int m=0; m<maskN; ++m) r = max(r, memo[N-1][m]);
        printf("%d\n", r);
    }
}