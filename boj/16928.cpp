#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int N, M, x, y, cost[101]={0}, path[101]={0};
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; ++i) {
        scanf("%d%d", &x, &y);
        path[x] = y;
    }
    for(int i=0; i<M; ++i) {
        scanf("%d%d", &x, &y);
        path[x] = y;
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        auto n = q.front(); q.pop();
        if(n == 100) break;
        for(int i=1; i<=6 && n+i<=100; ++i) {
            auto j = n+i;
            j = path[j] != 0 ? path[j] : j;
            if(cost[j] == 0) {
                cost[j] = cost[n] + 1;
                q.push(j);
            }
        }
    }
    printf("%d\n", cost[100]);
}