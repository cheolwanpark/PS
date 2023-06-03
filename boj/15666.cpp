#include <stdio.h>
#include <algorithm>
using namespace std;

int N, M, n[8], memo[8];
void print(int idx, int cnt) {
    if(cnt >= M) {
        for(int i=0; i<M; ++i) printf("%d ", memo[i]);
        printf("\n"); return;
    }

    for(int i=idx, j; i<N; ++i) {
        memo[cnt] = n[i];
        print(i, cnt+1);
        for(j=i; n[i] == n[j]; ++j);
        i = j-1;
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; ++i) scanf("%d", n+i);
    sort(n, n+N);
    print(0, 0);
}