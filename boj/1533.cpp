#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

typedef unsigned long long ull;
int N, S, E, T;
ull m[50][50]={0}, r[50][50], MOD=1000003;
char A[10][11];

void mul(ull a[50][50], ull b[50][50]) {
    int i, j, k;
    ull tmp[50][50];
    for(i=0; i<N; ++i) {
        for(j=0; j<N; ++j) {
            tmp[i][j] = 0;
            for(k=0; k<N; ++k) tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j])%MOD;
        }
    }
    memcpy(a, tmp, sizeof(tmp));
}

void pow(ull mat[50][50], int t) {
    if(t == 1) {
        memcpy(mat, m, sizeof(m));
    } else if(t&1) {
        pow(mat, t-1);
        mul(mat, m);
    } else {
        pow(mat, t/2);
        mul(mat, mat);
    }
}

int main() {
    scanf("%d%d%d%d", &N, &S, &E, &T);
    for(int i=0; i<N; ++i) {
        for(int j=1; j<5; ++j) m[i*5+j][i*5+j-1] = 1;
    }
    for(int i=0; i<N; ++i) {
        scanf("%s", A[i]);
        for(int j=0; j<N; ++j) {
            A[i][j] -= '0';
            if(A[i][j]) m[i*5][j*5+A[i][j]-1] = 1;
        }
    }
    N *= 5;
    pow(r, T);
    printf("%lld\n", r[(S-1)*5][(E-1)*5]);
}