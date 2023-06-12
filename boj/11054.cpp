#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int N, A[1000], inc[1000], dec[1000];
    scanf("%d", &N);
    for(int i=0; i<N; ++i) scanf("%d", A+i);
    for(int i=0; i<N; ++i) {
        inc[i] = 1;
        dec[N-1-i] = 1;
        for(int j=0; j<i; ++j) {
            if(A[j] < A[i]) inc[i] = max(inc[i], inc[j] + 1);
            if(A[N-1-j] < A[N-1-i]) dec[N-1-i] = max(dec[N-1-i], dec[N-1-j] + 1);
        }
    }
    int r = 0;
    for(int i=0; i<N; ++i) r = max(r, inc[i] + dec[i] - 1);
    printf("%d\n", r);
}