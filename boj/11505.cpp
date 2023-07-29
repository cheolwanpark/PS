#include <stdio.h>

using ll = long long;
const ll MAXN=1000000, MOD=1000000007;
int N, M, K, A, B, C, tree[(MAXN+1)*4]={0}, v[MAXN+1];

int init(int idx, int s, int e) {
    if(s == e) return tree[idx] = v[s];
    int m = (s+e)/2;
    ll mul = 1L*init(idx*2, s, m)*init(idx*2+1, m+1, e);
    return tree[idx] = mul % MOD;
}

int query(int idx, int s, int e, int l, int r) {
    if(e < l || r < s) return 1;
    else if(l <= s && e <= r) return tree[idx];
    int m = (s+e)/2;
    return 1L*query(idx*2, s, m, l, r)*query(idx*2+1, m+1, e, l, r) % MOD;
}

int update(int idx, int s, int e, int tgt, int val) {
    if(tgt < s || e < tgt) return tree[idx];
    if(s == e) return tree[idx] = val;
    int m = (s+e)/2;
    return tree[idx] = 1L*update(idx*2, s, m, tgt, val)*update(idx*2+1, m+1, e, tgt, val) % MOD;
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for(int i=1; i<=N; ++i) scanf("%d", v+i);
    init(1, 1, N);
    for(int i=0; i<M+K; ++i) {
        scanf("%d%d%d", &A, &B, &C);
        if(A == 1) {
            update(1, 1, N, B, C);
            v[B] = C;
        } else printf("%d\n", query(1, 1, N, B, C));
    }
}