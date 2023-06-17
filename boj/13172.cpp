#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;
ll MOD = 1000000007;
ll pow(ll a, ll b) {
    ll r = 1;
    while(b) {
        if(b&1) r = (r*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return r;
}
ll frac(ll a, ll b) {
    return (a * pow(b, MOD-2))%MOD;
}

int main() {
    ll M, N, S, r=0;
    scanf("%llu", &M);
    while(M--) {
        scanf("%llu%llu", &N, &S);
        r = (r + frac(S, N))%MOD;
    }
    printf("%llu\n", r);
}