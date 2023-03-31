// https://www.acmicpc.net/problem/1167
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int N;
vector<pair<int, int>> edges[100001];
char visit[100001];
pair<int, int> dfs(int node) {
    visit[node] = true;
    int ignore_history = 0;
    int best = 0, sub = 0;
    for(auto &edge : edges[node]) {
        if(!visit[edge.first]) {
            auto d = dfs(edge.first);
            d.first += edge.second;
            if(d.first > best) {
                sub = best;
                best = d.first;
            } else if(d.first > sub) {
                sub = d.first;
            }
            ignore_history = max(ignore_history, d.second);
        }
    }
    int old_ighis = ignore_history;
    ignore_history = max(ignore_history, best + sub);
    return {best, ignore_history};
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        int node, tgt, d;
        scanf("%d", &node);
        while(true) {
            scanf("%d", &tgt);
            if(tgt < 0) break;
            scanf("%d", &d);
            edges[node].push_back({tgt, d});
        }
    }
    auto ans = dfs(1);
    printf("%d\n", max(ans.first, ans.second));
}
