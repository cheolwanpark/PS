#include <stdio.h>
#include <algorithm>
using namespace std;

using ii = pair<int, int>;
const int MAXN = 100000, MIN=0, MAX=1000000001;
int N, M, a, b, arr[MAXN];
ii tree[MAXN*4];

ii build(int idx, int s, int e) {
    if(s == e) return tree[idx] = {arr[s], arr[s]};
    int mid = (s+e)/2;
    ii left = build(idx*2, s, mid), right = build(idx*2+1, mid+1, e);
    return tree[idx] = {min(left.first, right.first), max(left.second, right.second)};
}

ii query(int idx, int l, int r, int s, int e) {
    if(r < s || e < l) return {MAX, MIN};
    if(l <= s && e <= r) return tree[idx];
    int mid = (s+e)/2;
    ii left = query(idx*2, l, r, s, mid), right = query(idx*2+1, l, r, mid+1, e);
    return {min(left.first, right.first), max(left.second, right.second)};
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; ++i) scanf("%d", arr+i);
    build(1, 0, N-1);
    for(int i=0; i<M; ++i) {
        scanf("%d%d", &a, &b);
        auto [mn, mx] = query(1, a-1, b-1, 0, N-1);
        printf("%d %d\n", mn, mx);
    }
}
