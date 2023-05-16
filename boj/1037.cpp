#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int C, D, mn=1000001, mx=1;
    scanf("%d", &C);
    for(int i=0; i<C; ++i) {
        scanf("%d", &D);
        mn = min(mn, D);
        mx = max(mx, D);
    }
    printf("%d\n", mn*mx);
}