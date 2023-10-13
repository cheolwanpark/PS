#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 987654321;
int N, M, K, S, D;
vector<pair<int, int>> edges[1001];
int d[1001][1001];

void dijkstra() {
    for(int i=1; i<=N; ++i)
        for(int j=1; j<=N; ++j) d[i][j] = INF;

    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, S, 0});
    d[S][0] = 0;
    while(!pq.empty()) {
        auto [c, node, passed_edges] = pq.top(); pq.pop();
        if(d[node][passed_edges] < -c) continue;
        for(auto edge : edges[node]) {
            auto [next, cost] = edge;
            if(-c + cost < d[next][passed_edges + 1]) {
                pq.push({c - cost, next, passed_edges + 1});
                d[next][passed_edges + 1] = -c + cost;
            }
        }
    }
}

int minCost(int psum) {
    int r = INF;
    for(int n=1; n < N; ++n)
        r = min(r, d[D][n] + n*psum);
    return r;
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    scanf("%d%d", &S, &D);
    for(int i=0, a, b, w; i<M; ++i) {
        scanf("%d%d%d", &a, &b, &w);
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }
    dijkstra();
    printf("%d\n", minCost(0));
    for(int i=0, p, psum=0; i<K; ++i) {
        scanf("%d", &p); psum += p;
        printf("%d\n", minCost(psum));
    }
}