#include <stdio.h>

int N, M, a[9];
void print(int n, int i) {
    if(i > M) {
        for(int j=1; j<=M; ++j) printf("%d ", a[j]);
        printf("\n");
        return;
    }
    for(;n<=N; ++n) {
        a[i] = n;
        print(n, i+1);
    }
}

int main() {
    scanf("%d%d", &N, &M);
    print(1, 1);
}