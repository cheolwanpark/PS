#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
typedef pair<int, int> ii;

int main() {
    int N, M, a, b, c;
    int cost[1001]={0};
    bool vst[1001]={0};
    vector<ii> e[1001];
    priority_queue<ii, vector<ii>, greater<ii>> q;
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; ++i) cost[i] = INF;
    for(int i=0; i<M; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        e[a].push_back({c, b});
    }
    scanf("%d%d", &a, &b);
    cost[a] = 0;
    q.push({0, a});
    while(!q.empty()) {
        auto [c, n] = q.top(); q.pop();
        if(vst[n]) continue;
        vst[n] = 1;
        if(n == b) break;
        
        for(auto edge : e[n]) {
            auto [cst, next] = edge;
            if(!vst[next] && c + cst < cost[next]) {
                cost[next] = c + cst;
                q.push({cost[next], next});
            }
        }
    }
    printf("%d\n", cost[b]);
}