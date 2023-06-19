#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int N, M, R, a, b, l, t[101], d[101][101]={0};

int main() {
    scanf("%d%d%d", &N, &M, &R);
    for(int i=1; i<=N; ++i) scanf("%d", t+i);
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) d[i][j] = i == j ? 0 : INF;
    }
    for(int i=0; i<R; ++i) {
        scanf("%d%d%d", &a, &b, &l);
        d[a][b] = d[b][a] = l;
    }
    for(int k=1; k<=N; ++k) {
        for(int i=1; i<=N; ++i) {
            for(int j=1; j<=N; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
    int r = 0;
    for(int i=1; i<=N; ++i) {
        int s = 0;
        for(int j=1; j<=N; ++j) {
            if(d[i][j] <= M) s += t[j];
        }
        r = max(r, s);
    }
    printf("%d\n", r);
}