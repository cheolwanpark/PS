#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXV=100000;
int V, E, A, B, disc[MAXV+1]={0};
vector<int> neighbors[MAXV+1];
vector<pair<int, int>> r;

int dfs(int u, int p) {
    static int T = 1;
    int low = disc[u] = T++;
    for(auto v : neighbors[u]) {
        if(v == p) continue;
        if(!disc[v]) {
            int low_v = dfs(v, u);
            if(disc[u] < low_v) r.emplace_back(min(u, v), max(u, v));
            low = min(low, low_v);
        } else low = min(low, disc[v]);
    }
    return low;
}

int main() {
    scanf("%d%d", &V, &E);
    for(int i=0; i<E; ++i) {
        scanf("%d%d", &A, &B);
        neighbors[A].push_back(B);
        neighbors[B].push_back(A);
    }
    for(int v=1; v<=V; ++v)
        if(!disc[v]) dfs(v, 0);
    sort(r.begin(), r.end());
    printf("%lu\n", r.size());
    for(auto e : r) printf("%d %d\n", e.first, e.second);
}