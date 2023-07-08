#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1000001;
vector<int> edges[MAXN];
int dp[MAXN][2];
bool visit[MAXN]={false};

void calc(int node) {
    visit[node] = true;
    dp[node][0] = 1;
    dp[node][1] = 0;
    for(auto next : edges[node]) {
        if(visit[next]) continue;
        calc(next);
        dp[node][0] += min(dp[next][1], dp[next][0]);
        dp[node][1] += dp[next][0];
    }
}

int main() {
    int N, u, v;
    scanf("%d", &N);
    for(int i=0; i<N-1; ++i) {
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    calc(1);
    printf("%d\n", min(dp[1][0], dp[1][1]));
}