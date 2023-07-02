#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M, S, E, s, e, d;
    scanf("%d%d", &N, &M);
    vector<int> degree(N+1, 0), dist(N+1, 0);
    vector<vector<int>> track(N+1);
    vector<pair<int, int>> edges[N+1];
    for(int i=0; i<M; ++i) {
        scanf("%d%d%d", &s, &e, &d);
        ++degree[e];
        edges[s].push_back({e, d});
    }
    scanf("%d%d", &S, &E);
    queue<int> q; q.push(S);
    while(!q.empty()) {
        auto node = q.front(); q.pop();
        for(auto edge : edges[node]) {
            auto [next, d] = edge;
            if(dist[next] < dist[node] + d) {
                dist[next] = dist[node] + d;
                track[next].clear(); 
            }
            if(dist[next] == dist[node] + d) track[next].push_back(node);
            
            --degree[next];
            if(!degree[next]) q.push(next);
        }
    }
    int cnt = 0;
    q.push(E); degree[E] = 1;
    while(!q.empty()) {
        auto node = q.front(); q.pop();
        cnt += track[node].size();
        for(auto next : track[node]) {
            if(!degree[next]) {
                q.push(next);
                degree[next] = 1;
            }
        }
    }
    printf("%d\n%d\n", dist[E], cnt);
}