#include <stdio.h>

typedef long long ll;

ll r[10]={0}, N, p=1, c;
void add(ll n, ll d) {
    while(n > 0) {
        r[n%10] += d;
        n /= 10;
    }
} 

int main() {
    scanf("%lld", &N);
    while(N > 0) {
        while(N%10 != 9 && N) {
            add(N, p);
            N--;
        }
        if(!N) break;
        c = (N/10 + 1);
        for(int i=0; i<10; ++i) r[i] += c*p;
        r[0] -= p;
        p *= 10;
        N /= 10;
    }
    for(int i=0; i<10; ++i) printf("%lld ", r[i]);
    printf("\n"); 
}