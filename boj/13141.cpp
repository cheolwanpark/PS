#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int N, M, S, E, L, d[201][201];
vector<tuple<int, int, int>> edges;

int main() {
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) d[i][j] = i == j ? 0 : INF;
    }
    while(M--) {
        scanf("%d%d%d", &S, &E, &L);
        d[S][E] = min(d[S][E], L);
        d[E][S] = min(d[E][S], L);
        edges.push_back({S, E, L});
    }
    for(int k=1; k<=N; ++k) {
        for(int i=1; i<=N; ++i) {
            for(int j=1; j<=N; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
    double r = INF;
    for(int i=1; i<=N; ++i) {
        double t = 0.0;
        for(auto &edge : edges) {
            auto [s, e, l] = edge;
            int mn = min(d[i][s], d[i][e]), mx = max(d[i][s], d[i][e]);
            if(mn + l <= mx) t = max(t, 1.0*mn + l);
            else t = max(t, 1.0*mx + (l - (mx-mn))/2.0);
        }
        r = min(r, t);
    }
    printf("%.1f\n", r);
}