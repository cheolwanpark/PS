#include <stdio.h>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int N, E;
int e[801][801]={0};

int main() {
    int a, b, c;
    scanf("%d%d", &N, &E);
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            if(i != j) e[i][j] = INF;
        }
    }
    for(int i=0; i<E; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }
    scanf("%d%d", &a, &b);

    for(int k=1; k<=N; ++k) {
        for(int i=1; i<=N; ++i) {
            for(int j=1; j<=N; ++j) e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
        }
    }

    int r1 = min(min(e[1][a] + e[a][b], INF) + e[b][N], INF);
    int r2 = min(min(e[1][b] + e[b][a], INF) + e[a][N], INF);
    int r = min(r1, r2);
    printf("%d\n", r == INF ? -1 : r);
}