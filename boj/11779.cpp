#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
const int INF = 987654321;

int main() {
    int N, M, prev[1001], a, b, c, d[1001];
    vector<ii> edges[1001];
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        edges[a].push_back({c, b});
    }
    scanf("%d%d", &a, &b);
    for(int i=1; i<=N; ++i) d[i]=INF;
    pq.push({0, a});
    d[a] = 0;
    while(!pq.empty()) {
        auto [cost, node] = pq.top(); pq.pop();
        if(node == b) break;
        if(cost > d[node]) continue;
        for(auto edge : edges[node]) {
            auto [cst, nxt] = edge;
            if(d[node] + cst < d[nxt]) {
                d[nxt] = d[node] + cst;
                prev[nxt] = node;
                pq.push({d[nxt], nxt});
            }
        }
    }
    stack<int> path;
    int cur = b;
    while(cur != a) {
        path.push(cur);
        cur = prev[cur];
    }
    printf("%d\n%d\n%d ", d[b], path.size()+1, a);
    while(!path.empty()) {
        printf("%d ", path.top()); path.pop();
    } printf("\n");
}