#include <stdio.h>

int main() {
    int T, N;
    scanf("%d", &T);

    int memo[11];
    memo[0] = 1;
    for(int i=1; i<=10; ++i) {
        memo[i] = 0;
        if(i - 1 >= 0) memo[i] += memo[i-1];
        if(i - 2 >= 0) memo[i] += memo[i-2];
        if(i - 3 >= 0) memo[i] += memo[i-3];
    }
    while(T--) {
        scanf("%d", &N);
        printf("%d\n", memo[N]);
    }
}