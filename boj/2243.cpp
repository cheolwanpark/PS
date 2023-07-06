#include <stdio.h>

const int MAX = 1000001;
int tree[MAX*4]={0};

void update(int idx, int tgt, int delta, int s, int e) {
    if(tgt < s || e < tgt) return;
    tree[idx] += delta;
    if(s == e) return;
    int mid = (s+e)/2;
    update(idx*2, tgt, delta, s, mid);
    update(idx*2+1, tgt, delta, mid+1, e);
}

int get_nth(int idx, int n, int s, int e) {
    if(s == e) return s;
    int mid = (s+e)/2;
    if(n <= tree[idx*2]) return get_nth(idx*2, n, s, mid);
    else return get_nth(idx*2+1, n-tree[idx*2], mid+1, e);
}

int main() {
    int N, A, B, C;
    scanf("%d", &N);
    while(N--) {
        scanf("%d", &A);
        if(A == 1) {
            scanf("%d", &B);
            C = get_nth(1, B, 1, MAX);
            printf("%d\n", C);
            update(1, C, -1, 1, MAX);
        } else {
            scanf("%d%d", &B, &C);
            update(1, B, C, 1, MAX);
        }
    }
}