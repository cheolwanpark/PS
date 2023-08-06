#include <stdio.h>

const int MOD = 10007;
int N, r=0, C[53][53];

int main() {
    for(int n=0; n<=52; ++n) C[n][0] = C[n][n] = 1;
    for(int n=1; n<=52; ++n) {
        for(int r=1; r<n; ++r) C[n][r] = (C[n-1][r-1] + C[n-1][r]) % MOD;
    }
    scanf("%d", &N);
    for(int i=1; 4*i<=N; ++i) {
        int d = C[13][i] * C[52-4*i][N-4*i] % MOD;
        if(i&1) r = (r + d) % MOD;
        else r = (MOD + r - d) % MOD;
    }
    printf("%d\n", r);
}