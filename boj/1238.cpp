#include <stdio.h>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int main() {
    int N, M, X, c[1001][1001]={0}, s, e, t;
    scanf("%d%d%d", &N, &M, &X);
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            if(i != j) c[i][j] = INF;
        }
    }
    for(int i=0; i<M; ++i) {
        scanf("%d%d%d", &s, &e, &t);
        c[s][e] = t;
    }

    for(int k=1; k<=N; ++k) {
        for(int i=1; i<=N; ++i) {
            for(int j=1; j<=N; ++j) c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
        }
    }

    int r = 0;
    for(int i=1; i<=N; ++i) r = max(r, c[i][X] + c[X][i]);
    printf("%d\n", r);
}