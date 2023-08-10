#include <stdio.h>
using namespace std;

const int MAXN=500000;
int N, id, tree[MAXN*4]={0}, m[1000001];

void set(int idx, int s, int e, int tgt) {
    if(tgt < s || e < tgt) return;
    tree[idx] += 1;
    if(s == e) return;
    int m = (s+e)/2;
    set(idx*2, s, m, tgt);
    set(idx*2+1, m+1, e, tgt);
}

int query(int idx, int s, int e, int l, int r) {
    if(e < l || r < s) return 0;
    if(l <= s && e <= r) return tree[idx];
    int m = (s+e)/2;
    return query(idx*2, s, m, l, r) + query(idx*2+1, m+1, e, l, r);
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        scanf("%d", &id);
        m[id] = i;
    }
    long long r=0;
    for(int i=0, n; i<N; ++i) {
        scanf("%d", &id); n = m[id];
        r += query(1, 0, N-1, n, N-1);
        set(1, 0, N-1, n);
    }
    printf("%lld\n", r);
}