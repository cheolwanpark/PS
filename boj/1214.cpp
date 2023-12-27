#include <stdio.h>
#include <algorithm>
using namespace std;

int solve(int D, int P, int Q) {
    if(D%P == 0 || D%Q == 0) return D;
    if(P < Q) swap(P, Q);
    int r = (D/P+1)*P;
    for(int i=D/P, remain, pay; i >= 0; --i) {
        remain = D - P*i;
        if(remain%Q == 0) return D;
        pay = P*i + Q*(remain/Q+1);
        if(r == pay) return r;
        r = min(r, pay);
    }
    return r;
}

int main() {
    int D, P, Q;
    scanf("%d%d%d", &D, &P, &Q);
    printf("%d\n", solve(D, P, Q));
}