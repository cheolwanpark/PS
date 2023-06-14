#include <stdio.h>
#include <queue>
using namespace std;

int N, K, c[100001], w[100001]={0};
queue<int> q;
void push(int n, int prev) {
    if(n < 0 || n > 100000) return;
    int cst = c[prev] + 1;
    if(w[n] == 0) {
        w[n] = w[prev];
        c[n] = cst;
        q.push(n);
    } else if(c[n] == cst) {
        w[n] += w[prev];
    }
}

int main() {
    scanf("%d%d", &N, &K);
    q.push(N); w[N] = 1;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        if(cur == K) break;
        push(cur-1, cur);
        push(cur+1, cur);
        push(cur*2, cur);
    }
    printf("%d\n%d\n", c[K], w[K]);
}