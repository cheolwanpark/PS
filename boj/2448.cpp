#include <stdio.h>

void blanks(int n) {
    for(int i=0; i<n; ++i) printf(" ");
}
void stars(int n) {
    for(int i=0; i<n; ++i) printf("*");
}

void print(int i, int N) {
    if(N == 3) {
        if(i%3 == 0) {
            blanks(2); stars(1); blanks(2);
        } else if(i%3 == 1) {
            blanks(1); stars(1); blanks(1); stars(1); blanks(1);
        } else {
            stars(5);
        }
    } else {
        if(i%N < N/2) {
            blanks(N/2); print(i%N, N/2); blanks(N/2);
        } else {
            print(i%N, N/2); blanks(1); print(i%N, N/2);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        print(i, N); printf("\n");
    }
}