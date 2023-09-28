#include <stdio.h>
#include <string.h>

const int MOD = 10007;
char S[1001];
int dp[1001][1001], N;

int main() {
    scanf("%s", S); N = strlen(S);
    dp[0][0] = 1;
    for(int i=1; i<N; ++i) {
        dp[i][i] = 1;
        if(S[i-1] == S[i]) dp[i-1][i] = 3;
        else dp[i-1][i] = 2;
    }
    for(int L=3; L<=N; ++L) {
        for(int i=0, j=L-1; j<N; ++i, ++j) {
            dp[i][j] = (MOD + dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]) % MOD;
            if(S[i] == S[j]) dp[i][j] = (dp[i][j] + dp[i+1][j-1] + 1) % MOD;
        }
    }
    printf("%d\n", dp[0][N-1]);
}