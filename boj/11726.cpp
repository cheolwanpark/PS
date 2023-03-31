// https://www.acmicpc.net/problem/11726
#include <stdio.h>

int memo[1001];
int N;

int main() {
    scanf("%d", &N);
    memo[1] = 1;
    memo[2] = memo[1] + 1;

    for(int i=3; i<=N; ++i) {
        memo[i] = (memo[i-1] + memo[i-2]) % 10007;
    }
    printf("%d\n", memo[N]);
}