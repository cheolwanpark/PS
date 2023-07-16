#include <stdio.h>

using ll = long long;

int main() {
    ll N, r;
    scanf("%lld", &N); r = N;
    for(ll p=2; p*p<=N; ++p) {
        if(N%p == 0) r = r / p * (p-1);
        while(N%p == 0) N /= p;
    }
    if(N != 1) r = r / N * (N-1);
    printf("%lld\n", r);
}