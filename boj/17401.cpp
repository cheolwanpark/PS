#include <stdio.h>
#include <string.h>

const int MOD = 1000000007;
int T, N, D, M, a, b, c, m[101][21][21]={0}, dp[101][21][21]={0}, r[21][21]={0}, tmp[21][21];

int main() {
    scanf("%d%d%d", &T, &N, &D);
    for(int t=1; t<=T; ++t) {
        scanf("%d", &M);
        while(M--) {
            scanf("%d%d%d", &a, &b, &c);
            m[t][a][b] = c;
        }
    }
    for(int i=1; i<=N; ++i) dp[0][i][i] = r[i][i] = 1;
    for(int t=1; t<=T; ++t) {
        for(int i=1; i<=N; ++i) {
            for(int j=1; j<=N; ++j) {
                for(int k=1; k<=N; ++k) dp[t][i][j] = (dp[t][i][j] + 1LL*dp[t-1][i][k]*m[t][k][j]) % MOD;
            }
        }
    }
    int d = D / T, t = D % T;
    while(d > 0) {
        if(d&1) {
            for(int i=1; i<=N; ++i) {
                for(int j=1; j<=N; ++j) {
                    tmp[i][j] = 0;
                    for(int k=1; k<=N; ++k) tmp[i][j] = (tmp[i][j] + 1LL*r[i][k]*dp[T][k][j]) % MOD;
                }
            }
            memcpy(r, tmp, sizeof(tmp));
        }
        for(int i=1; i<=N; ++i) {
            for(int j=1; j<=N; ++j) {
                tmp[i][j] = 0;
                for(int k=1; k<=N; ++k) tmp[i][j] = (tmp[i][j] + 1LL*dp[T][i][k]*dp[T][k][j]) % MOD;
            }
        }
        memcpy(dp[T], tmp, sizeof(tmp));
        d >>= 1;
    }
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            tmp[i][j] = 0;
            for(int k=1; k<=N; ++k) tmp[i][j] = (tmp[i][j] + 1LL*r[i][k]*dp[t][k][j]) % MOD;
            printf("%d ", tmp[i][j]);
        }
        printf("\n");
    }
}