#include <stdio.h>
#include <string.h>

const int MAXN=100000;
int T, N, M, q, top, idx[MAXN+1], tree[(MAXN+1)*2*4];

int query(int idx, int s, int e, int l, int r) {
    int m = (s+e)/2;
    if(e < l || r < s) return 0;
    else if(l <= s && e <= r) return tree[idx];
    else return query(idx*2, s, m, l, r) + query(idx*2+1, m+1, e, l, r);
}

void update(int idx, int s, int e, int tgt, int delta) {
    if(tgt < s || e < tgt) return;
    tree[idx] += delta;
    if(s == e) return;
    int m = (s+e)/2;
    update(idx*2, s, m, tgt, delta);
    update(idx*2+1, m+1, e, tgt, delta);
}

int main() {
    scanf("%d", &T);
    while(T--) {
        memset(idx, 0, sizeof(idx));
        memset(tree, 0, sizeof(tree));
        scanf("%d%d", &N, &M);
        for(int i=0; i<N; ++i) {
            idx[N-i] = i;
            update(1, 0, N+M, i, 1);
        }
        top = N;
        for(int i=0; i<M; ++i) {
            scanf("%d", &q);
            printf("%d ", query(1, 0, N+M, idx[q], N+M)-1);
            update(1, 0, N+M, idx[q], -1);
            update(1, 0, N+M, top, 1);
            idx[q] = top++;
        }
        printf("\n");
    }
}