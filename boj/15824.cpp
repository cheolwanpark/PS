#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN=300000, MOD=1000000007;
int N, r=0, S[MAXN], p[MAXN+1];

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; ++i) scanf("%d", S+i);
    p[0] = 1;
    for(int i=1; i<=N; ++i) p[i] = 2L*p[i-1] % MOD;
    sort(S, S+N);
    for(int i=0; i<N; ++i) r = ((1L*MOD + p[i] - p[N-i-1]) % MOD * S[i] + r) % MOD;
    printf("%d\n", r);
}