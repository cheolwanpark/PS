#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
int uf[MAXN+1], d[MAXN+1];

pair<int, int> find(int n) {
    if(uf[n] == n) return {n, 0};
    else {
        auto [root, diff] = find(uf[n]);
        uf[n] = root;
        d[n] += diff;
        return {uf[n], d[n]};
    }
}

void uni(int a, int b, int w) {
    auto [root1, d1] = find(a);
    auto [root2, d2] = find(b);
    uf[root1] = root2;
    d[root1] = w + d2 - d1;
}

int main() {
    int N, M, a, b, w;
    char cmd[2];
    while(true) {
        scanf("%d%d", &N, &M);
        if(!N && !M) break;
        for(int i=1; i<=N; ++i) {
            uf[i] = i;
            d[i] = 0;
        }
        while(M--) {
            scanf("%s%d%d", cmd, &a, &b);
            if(cmd[0] == '!') {
                scanf("%d", &w);
                uni(a, b, w);
            } else {
                auto [root1, d1] = find(a);
                auto [root2, d2] = find(b);
                if(root1 != root2) printf("UNKNOWN\n");
                else printf("%d\n", d1 - d2);
            }
        }
    }
}