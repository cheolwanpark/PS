#include <stdio.h>
#include <algorithm>
using namespace std;

int p[500001];
int find(int n) {
    if(p[n] == n) return n;
    else return p[n] = find(p[n]);
}

void uni(int a, int b) {
    p[find(a)] = find(b);
}

int main() {
    int N, M, a, b;
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; ++i) p[i] = i;
    for(int i=1; i<=M; ++i) {
        scanf("%d%d", &a, &b);
        if(find(a) == find(b)) {
            printf("%d\n", i);
            return 0;
        }
        else uni(a, b);
    }
    printf("0\n");
}