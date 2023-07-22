#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN=100000, LGN=17;
int N, M, u, v, depth[MAXN+1]={0}, parent[MAXN+1][LGN];
vector<int> edges[MAXN+1];

void setDepth(int node, int d, int p) {
    depth[node] = d;
    parent[node][0] = p;
    for(auto next : edges[node]) {
        if(!depth[next]) setDepth(next, d+1, node);
    }
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N-1; ++i) {
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    setDepth(1, 1, 0);
    for(int i=1; i<LGN; ++i) {
        for(int nd=1; nd<=MAXN; ++nd) {
            int p = parent[nd][i-1];
            parent[nd][i] = p ? parent[p][i-1] : 0;
        }
    }

    scanf("%d", &M);
    for(int i=0; i<M; ++i) {
        scanf("%d%d", &u, &v);
        if(depth[u] < depth[v]) swap(u, v);
        for(int i=LGN-1; i>=0; --i) {
            if((depth[u] - depth[v]) & (1 << i)) u = parent[u][i];
        }
        if(u != v) {
            for(int i=LGN-1; i>=0; --i) {
                if(parent[u][i] && parent[u][i] != parent[v][i]) {
                    u = parent[u][i];
                    v = parent[v][i];
                }
            }
            printf("%d\n", parent[u][0]);
        } else printf("%d\n", u);
    }
}