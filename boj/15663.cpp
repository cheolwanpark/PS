#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int N, M, n[8], memo[8], used[8]={0};
void print(int cnt) {
    if(cnt >= M) {
        for(int i=0; i<M; ++i) printf("%d ", memo[i]);
        printf("\n"); return;
    }
    for(int i=0, j; i<N; ++i) {
        if(used[i]) continue;
        memo[cnt] = n[i];
        used[i] = 1;
        print(cnt+1);
        used[i] = 0;
        for(j=i;n[i] == n[j]; ++j);
        i = j-1;
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; ++i) scanf("%d", n+i);
    sort(n, n+N);
    print(0);
}