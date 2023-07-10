#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN=100000, LOGN=18, MAXC=1000001;
int N, K, A, B, C, parent[MAXN+1][LOGN]={0}, minc[MAXN+1][LOGN]={0}, maxc[MAXN+1][LOGN]={0}, depth[MAXN+1]={0};
vector<pair<int, int>> edges[MAXN+1];

void setup(int node, int p, int d, int c) {
    parent[node][0] = p;
    depth[node] = d;
    minc[node][0] = maxc[node][0] = c;
    for(auto edge : edges[node]) {
        if(!depth[edge.first]) setup(edge.first, node, d+1, edge.second);
    }
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<N; ++i) {
        scanf("%d%d%d", &A, &B, &C);
        edges[A].emplace_back(B, C);
        edges[B].emplace_back(A, C);
    }
    setup(1, 0, 1, 0);
    for(int k=1; k<LOGN; ++k) {
        for(int n=1; n<=N; ++n) {
            int p = parent[n][k-1];
            if(!p || !parent[p][k-1]) continue;
            parent[n][k] = parent[p][k-1];
            minc[n][k] = min(minc[n][k-1], minc[p][k-1]);
            maxc[n][k] = max(maxc[n][k-1], maxc[p][k-1]);
        }
    }

    scanf("%d", &K);
    for(int k=0; k<K; ++k) {
        scanf("%d%d", &A, &B);
        int min_cost=MAXC, max_cost=0;
        if(depth[A] > depth[B]) swap(A, B);
        for(int i=LOGN-1; i>=0; --i) {
            if(depth[B] - depth[A] >= (1 << i)) {
                min_cost = min(min_cost, minc[B][i]);
                max_cost = max(max_cost, maxc[B][i]);
                B = parent[B][i];
            }
        }
        if(A != B) {
            for(int i=LOGN-1; i>=0; --i) {
                if(parent[A][i] && parent[A][i] != parent[B][i]) {
                    min_cost = min(min_cost, min(minc[A][i], minc[B][i]));
                    max_cost = max(max_cost, max(maxc[A][i], maxc[B][i]));
                    A = parent[A][i];
                    B = parent[B][i];
                }
            }
            min_cost = min(min_cost, min(minc[A][0], minc[B][0]));
            max_cost = max(max_cost, max(maxc[A][0], maxc[B][0]));   
        }
        printf("%d %d\n", min_cost, max_cost);
    }
}