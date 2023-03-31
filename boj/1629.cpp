// https://www.acmicpc.net/problem/1629
#include <stdio.h>

typedef unsigned long long llu;
llu solve(llu A, llu B, llu C) {
    if(B <= 0) return 1;
    if(B%2) {
        return (solve(A, B-1, C) * A) % C;
    } else {
        llu v = solve(A, B/2, C);
        return (v * v) % C;
    }
}

int main() {
    llu A, B, C;
    scanf("%llu%llu%llu", &A, &B, &C);
    printf("%llu\n", solve(A % C, B, C));
}