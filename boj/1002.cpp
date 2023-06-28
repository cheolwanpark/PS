#include <stdio.h>

int square(int n) {
    return n*n;
}

int main() {
    int T, x1, y1, r1, x2, y2, r2;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
        int d_square = square(x2 - x1) + square(y2 - y1);
            
        if(d_square == 0) printf("%d\n", r1 == r2 ? (r1 ? -1 : 1) : 0);
        else if(d_square == square(r1 + r2) || d_square == square(r1 - r2)) printf("1\n");
        else if(square(r1 - r2) < d_square && d_square < square(r1 + r2)) printf("2\n");
        else printf("0\n");
    }
}