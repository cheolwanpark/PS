#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

int N, m[5][5], r[5][5], t[5][5];
long long B;
void mul(int a[][5], int b[][5]) {
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            t[i][j] = 0;
            for(int k=0; k<N; ++k) {
                t[i][j] = (t[i][j] + a[i][k] * b[k][j])%1000;
            }
        }
    }
    memcpy(a, t, sizeof(t));
}

int main() {
    scanf("%d%lld", &N, &B);
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            scanf("%d", &m[i][j]);
            m[i][j] %= 1000;
        }
    }
    memcpy(r, m, sizeof(m));

    stack<int> op;
    while(B > 1) {
        if(B%2LL == 0) {
            op.push(0);
            B /= 2;
        } else {
            op.push(1);
            B -= 1;
        }
    }
    while(!op.empty()) {
        if(op.top()) mul(r, m);
        else mul(r, r);
        op.pop();
    }
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) printf("%d ", r[i][j]);
        printf("\n");
    }
}