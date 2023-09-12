#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN=100000;
int N, a, b, c, energy[MAXN+1], visit[MAXN+1]={0};
pair<int, long long> parent[18][MAXN+1];
vector<pair<int, int>> edges[MAXN+1];

void dfs(int node, int p, int cost) {
    parent[0][node] = {p, cost};
    visit[node] = true;
    for(auto edge : edges[node]) {
        auto [next, cost] = edge;
        if(!visit[next]) dfs(next, node, cost);
    }
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; ++i) scanf("%d", energy+i);
    for(int i=0; i<N-1; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        edges[a].emplace_back(b, c);
        edges[b].emplace_back(a, c);
    }

    dfs(1, 0, 0);
    for(int i=1; i<=17; ++i) {
        for(int j=1; j<=N; ++j) {
            auto [p, c1] = parent[i-1][j];
            auto [pp, c2] = parent[i-1][p];
            parent[i][j] = {pp, c1 + c2};
        }
    }

    for(int i=1, t; i<=N; ++i) {
        t = i;
        for(int j=17; j>=0; --j) {
            if(parent[j][t].first != 0 && parent[j][t].second <= energy[i]) {
                energy[i] -= parent[j][t].second;
                t = parent[j][t].first;
            }
        }
        printf("%d\n", t);
    }
}