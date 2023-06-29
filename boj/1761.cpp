#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int N, M, a, b, c, order[40001]={0, 1}, d[40001]={0}, par[40001];
vector<pair<int, int>> edges[40001];

int shared_parent(int a, int b) {
    if(a == b) return a;
    else if(order[a] < order[b]) return shared_parent(a, par[b]);
    else if(order[a] > order[b]) return shared_parent(par[a], b);
    else return shared_parent(par[a], par[b]);
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N-1; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front(), nxt; q.pop();
        for(auto edge : edges[cur]) {
            nxt = edge.first;
            if(!order[nxt]) {
                order[nxt] = order[cur] + 1;
                d[nxt] = d[cur] + edge.second;
                par[nxt] = cur;
                q.push (nxt);
            }
        }
    }
    scanf("%d", &M);
    for(int i=0; i<M; ++i) {
        scanf("%d%d", &a, &b);
        int parent = shared_parent(a, b);
        printf("%d\n", d[a] + d[b] - 2*d[parent]);
    }
}