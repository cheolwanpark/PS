#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

using ii = pair<int, int>;
int N, M, S, D, U, V, P, e[500][500], d[500];
vector<int> prevs[500];

void dijkstra() {
    for(int i=0; i<N; ++i) {
        prevs[i].clear();
        d[i] = -1;
    }
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, S}); d[S] = 0; prevs[S].push_back(-1);
    while(!pq.empty()) {
        auto [c, n] = pq.top(); pq.pop();
        if(d[n] < c) continue;
        for(int i=0, dist; i<N; ++i) {
            if(!e[n][i]) continue;
            dist = c + e[n][i];
            if(prevs[i].empty() || dist < d[i]) {
                d[i] = dist;
                prevs[i].clear();
                pq.push({d[i], i});
            }
            if(d[i] == dist) prevs[i].push_back(n);
        }
    }
}

int main() {
    while(true) {
        scanf("%d%d", &N, &M);
        if(!N && !M) break;
        scanf("%d%d", &S, &D);
        memset(e, 0, sizeof(e));
        for(int i=0; i<M; ++i) {
            scanf("%d%d%d", &U, &V, &P);
            e[U][V] = P;
        }
        dijkstra();
        queue<int> q;
        q.push(D); d[D] = 0;
        while(!q.empty()) {
            auto n = q.front(); q.pop();
            for(auto prev : prevs[n]) {
                e[prev][n] = 0;
                if(d[prev]) {
                    d[prev] = 0;
                    q.push(prev);
                }
            }
        }
        dijkstra();
        printf("%d\n", d[D]);
    }
}