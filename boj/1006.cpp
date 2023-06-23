#include <stdio.h>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int T, N, W, n[10000][2], memo[10000][3];
void solve(int i) {
    for(;i<N; ++i) {
        memo[i][0] = min(memo[i-1][2] + 1, memo[i-1][1] + (n[i][0] + n[i-1][0] <= W ? 1 : 2));
        memo[i][1] = min(memo[i-1][2] + 1, memo[i-1][0] + (n[i][1] + n[i-1][1] <= W ? 1 : 2));
        memo[i][2] = min((n[i][0] + n[i][1] <= W ? memo[i-1][2] + 1 : INF), min(memo[i][0], memo[i][1]) + 1);
        if(n[i][0] + n[i-1][0] <= W && n[i][1] + n[i-1][1] <= W) 
            memo[i][2] = min(memo[i][2], (i > 1 ? memo[i-2][2] : 0) + 2);
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &N, &W);
        for(int i=0; i<N; ++i) scanf("%d", &n[i][0]);
        for(int i=0; i<N; ++i) scanf("%d", &n[i][1]);
        int r = INF, 
            upside = N > 1 && n[0][0] + n[N-1][0] <= W, 
            downside = N > 1 && n[0][1] + n[N-1][1] <= W, 
            t[2] = {n[0][0], n[0][1]};
        memo[0][0] = memo[0][1] = 1;
        memo[0][2] = n[0][0] + n[0][1] <= W ? 1 : 2;
        solve(1);
        r = min(r, memo[N-1][2]);
        if(upside) {
            n[0][0] = INF;
            memo[0][0] = 1;
            memo[0][1] = INF;
            memo[0][2] = 2;
            solve(1);
            r = min(r, memo[N-1][1]);
            n[0][0] = t[0];
        }
        if(downside) {
            n[0][1] = INF;
            memo[0][0] = INF;
            memo[0][1] = 1;
            memo[0][2] = 2;
            solve(1);
            r = min(r, memo[N-1][0]);
            n[0][1] = t[1];
        }
        if(upside && downside)  {
            n[0][0] = n[0][1] = INF;
            memo[1][0] = memo[1][1] = 3;
            memo[1][2] = n[1][0] + n[1][1] <= W ? 3 : 4;
            solve(2);
            r = min(r, memo[N-2][2]);
        }
        printf("%d\n", r);
    }
}