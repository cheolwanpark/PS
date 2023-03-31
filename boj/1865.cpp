// https://www.acmicpc.net/problem/1865
#include <stdio.h>
#include <vector>
#include <memory.h>
using namespace std;

struct Edge {
    int s;
    int e;
    int t;
};

int solve(int N, vector<Edge> &edges) {
    int dist[501] = {0,};
    for(int i=0; i<N; ++i) {
        for(auto &e : edges) {
            if(dist[e.s] + e.t < dist[e.e]) {
                dist[e.e] = dist[e.s] + e.t;
                if(i == N-1) return true;
            }
        }
    }
    return false;
}


int main() {
    int TC;
    int S, E, T;
    scanf("%d", &TC);
    while(TC--) {
        int N, M, W;
        vector<Edge> edges;
        scanf("%d%d%d", &N, &M, &W);
        for(int i=0; i<M; ++i) {
            scanf("%d%d%d", &S, &E, &T);
            edges.push_back({S, E, T});
            edges.push_back({E, S, T});
        }
        for(int i=0; i<W; ++i) {
            scanf("%d%d%d", &S, &E, &T);
            edges.push_back({S, E, -T});
        }
        printf("%s\n", solve(N, edges) ? "YES" : "NO");
    }
}