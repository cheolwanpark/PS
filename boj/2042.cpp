#include <stdio.h>

typedef long long ll;
ll N, M, K, a, b, c, n[1000000], tree[(1<<21) + 1]={0};

ll init(int s, int e, int idx) {
    if(s == e) return tree[idx] = n[s];
    int m = (s+e)/2;
    return tree[idx] = init(s, m, idx*2) + init(m+1, e, idx*2+1);
}

ll q(int s, int e, int idx, int l, int r) {
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return tree[idx];
    int m = (s+e)/2;
    return q(s, m, idx*2, l, r) + q(m+1, e, idx*2+1, l, r);
}

void u(int s, int e, int idx, int pos, ll diff) {
    if(pos < s || e < pos) return;
    tree[idx] += diff;
    if(s == e) return;
    int m = (s+e)/2;
    u(s, m, idx*2, pos, diff);
    u(m+1, e, idx*2+1, pos, diff);
}

int main() {
    scanf("%lld%lld%lld", &N, &M, &K);
    for(int i=0; i<N; ++i) scanf("%lld", n+i);
    init(0, N-1, 1);
    for(int i=0; i<M+K; ++i) {
        scanf("%lld%lld%lld", &a, &b, &c);
        if(a == 1) {
            u(0, N-1, 1, b-1, c-n[b-1]);
            n[b-1] = c;
        } else printf("%lld\n", q(0, N-1, 1, b-1, c-1));
    }
}