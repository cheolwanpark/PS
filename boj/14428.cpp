#include <stdio.h>

const int MAXN=100000, INF=987654321;
int N, M, a, b, c, A[MAXN+1], tree[(MAXN+1)*4];

int min_idx(int i, int j) {
    if(i == 0 || j == 0) return i == 0 ? j : i;
    else if(A[i] == A[j]) return i < j ? i : j;
    else return A[i] < A[j] ? i : j;
}
int init(int idx, int s, int e) {
    if(s == e) return tree[idx] = s;
    int m = (s+e)/2;
    return tree[idx] = min_idx(init(idx*2, s, m), init(idx*2+1, m+1, e));
}

int query(int idx, int s, int e, int l, int r) {
    if(e < l || r < s) return 0;
    if(l <= s && e <= r) return tree[idx];
    int m = (s+e)/2;
    return min_idx(query(idx*2, s, m, l, r), query(idx*2+1, m+1, e, l, r));
}

int update(int idx, int s, int e, int tgt) {
    if(tgt < s || e < tgt) return tree[idx];
    if(s == e) return tree[idx] = s;
    int m = (s+e)/2;
    return tree[idx] = min_idx(update(idx*2, s, m, tgt), update(idx*2+1, m+1, e, tgt));
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; ++i) scanf("%d", A+i);
    init(1, 1, N);
    scanf("%d", &M);
    for(int i=0; i<M; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        if(a == 1) {
            A[b] = c;
            update(1, 1, N, b);
        } else printf("%d\n", query(1, 1, N, b, c));
    }
}