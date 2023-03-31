// https://www.acmicpc.net/problem/11404
#include <stdio.h>
#include <algorithm>
using namespace std;

int INF = 987654321;
int dist[101][101];
int N, M;
int a, b, c;

int main() {
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) dist[i][j] = (i == j ? 0 : INF);
    }
    for(int i=0; i<M; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        dist[a][b] = min(dist[a][b], c);
    }

    for(int k=1; k<=N; ++k) {
        for(int a=1; a<=N; ++a) {
            for(int b=1; b<=N; ++b) {
                dist[a][b] = min(dist[a][b], dist[a][k] + dist[k][b]);
            }
        }
    }
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            if(dist[i][j] == INF) printf("0 ");
            else printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}