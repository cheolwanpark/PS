#include <stdio.h>

const int MOD = 1000000007, MAXN=4000000;
int M, N, K, f[MAXN+1];

int pow(int a, int b) {
    int r = 1;
    while(b > 0) {
        if(b&1) r = 1LL*r*a % MOD;
        b = b >> 1;
        a = 1LL*a*a % MOD;
    }
    return r;
}

int main() {
    scanf("%d", &M);
    f[0] = 1;
    for(int i=1; i<=MAXN; ++i) f[i] = 1LL*f[i-1]*i % MOD;
    while(M--) {
        scanf("%d%d", &N, &K);
        printf("%lld\n", 1LL*f[N]*pow(1LL*f[N-K]*f[K] % MOD, MOD-2) % MOD);
    }
}