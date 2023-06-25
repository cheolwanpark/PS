#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

typedef unsigned long long ull;

int mod(const string &N, int K) {
    int r = 0, pow = 1;
    for(int i=0; i<N.length(); ++i) {
        int n = N[N.length()-1-i] - '0';
        r = (r + pow*(n%K))%K;
        pow = (pow*10)%K;
    }
    return r;
}

ull gcd(ull a, ull b) {
    if(a < b) return gcd(b, a);
    return b == 0 ? a : gcd(b, a%b);
}

int N, K, totalL=0;
char n[51];
vector<string> a;
vector<int> r, l, p10;
ull memo[100][1<<15]={0}, q=1;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        scanf("%s", n);
        a.push_back(string(n));
        l.push_back(a[i].length());
        totalL += l[i];
        q *= i+1;
    }
    scanf("%d", &K);
    p10.push_back(1%K);
    for(int i=1; i<=totalL; ++i) p10.push_back((p10[i-1]*10)%K);
    for(auto &s : a) r.push_back(mod(s, K));

    for(int i=0; i<N; ++i) memo[r[i]][1<<i] = 1;
    for(int i=1; i<N; ++i) {
        for(int m=0; m<(1<<N); ++m) {
            int lsum=0, bitc=0;
            for(int i=0; i<N; ++i) {
                if(m&(1<<i)) {
                    lsum += l[i];
                    ++bitc;
                }
            }
            if(bitc != i) continue;
            for(int j=0; j<N; ++j) {
                if(m&(1<<j)) continue;
                for(int v=0; v<K; ++v) {
                    memo[(v + r[j]*p10[lsum])%K][m|(1<<j)] += memo[v][m];
                }
            }
        }
    }
    ull p = memo[0][(1<<N)-1];
    ull dv = p != 0 ? gcd(p, q) : q;
    p /= dv; q /= dv;
    printf("%llu/%llu\n", p, q);
}