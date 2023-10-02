#include <stdio.h>
#include <vector>
#include <climits>
using namespace std;

using ll = long long;
const int MAXN=100000;
int N, D, V;
ll tree[(MAXN+2)*4] = {0};
vector<int> neg = {0};

ll query(int i, int s, int e, int l, int r) {
    if(r < s || e < l) return LLONG_MIN;
    if(l <= s && e <= r) return tree[i];
    int m = (s+e)/2;
    return max(query(i*2, s, m, l, r), query(i*2+1, m+1, e, l, r));
}

ll update(int i, int s, int e, int tgt, ll v) {
    if(s == e) return tree[i] = v;
    int m = (s+e)/2;
    if(tgt <= m) update(i*2, s, m, tgt, v);
    else update(i*2+1, m+1, e, tgt, v);
    return tree[i] = max(tree[i*2], tree[i*2+1]);
}

int main() {
    scanf("%d%d", &N, &D);
    update(1, 0, N+1, 0, 0);
    for(int i=1; i<=N; ++i) {
        scanf("%d", &V);
        ll mx = max(query(1, 0, N+1, max(0, i-D), i-1), 0LL) + V;
        update(1, 0, N+1, i, mx);
    }
    printf("%lld\n", query(1, 0, N+1, 1, N));
}