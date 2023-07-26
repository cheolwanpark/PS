#include <stdio.h>
#include <set>
using namespace std;

const int MAXN=5000, MAXA=200000;
int W, N, A[MAXN+1];
pair<int, int> idx[MAXA*2+1]={{0, 0}};

int main() {
    scanf("%d%d", &W, &N);
    for(int i=1; i<=N; ++i) scanf("%d", A+i);
    for(int i=1; i<=N; ++i) {
        for(int j=i+1; j<=N; ++j) {
            int s = A[i] + A[j];
            if(!idx[s].first) idx[s] = {i, j};
        }
    }
    bool possible = false;
    for(int i=1; i<=N; ++i) {
        for(int j=i+1; j<=N; ++j) {
            int tgt = W - A[i] - A[j];
            if(tgt < 0 || tgt > MAXA*2 || !idx[tgt].first) continue;
            auto [k, h] = idx[tgt];
            if(i != k && i != h && j != k && j != h) {
                possible = true;
                break;
            }
        }
        if(possible) break;
    }
    printf("%s\n", possible ? "YES" : "NO");
}