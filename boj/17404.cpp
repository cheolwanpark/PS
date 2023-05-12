#include <stdio.h>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int N, cost[1000][3];
int solve(int col) {
    int memo[1000][3], r=INF;
    for(int i=0; i<3; ++i) memo[0][i] = i == col ? cost[0][i] : INF;
    for(int i=1; i<N; ++i) {
        memo[i][0] = min(memo[i-1][1], memo[i-1][2]) + cost[i][0]; 
        memo[i][1] = min(memo[i-1][0], memo[i-1][2]) + cost[i][1]; 
        memo[i][2] = min(memo[i-1][0], memo[i-1][1]) + cost[i][2];
    }
    for(int i=0; i<3; ++i) r = min(r, i != col ? memo[N-1][i] : INF);
    return r;
}

int main() {
    int r = INF;
    scanf("%d", &N);
    for(int i=0; i<N; ++i) scanf("%d%d%d", cost[i], cost[i]+1, cost[i]+2);
    for(int i=0; i<3; ++i) r = min(r, solve(i));
    printf("%d\n", r);
}