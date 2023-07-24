#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXV=10000;
int V, E, A, B, disc[MAXV+1]={0}, low[MAXV+1];
vector<int> nbr[MAXV+1];
bool ap[MAXV+1]={false};

int dfs(int u, int p) {
    static int T=1;
    disc[u] = low[u] = T++;
    int subgraphs = 0;
    for(auto v : nbr[u]) {
        if(v == p) continue;
        if(!disc[v]) {
            ++subgraphs;
            dfs(v, u);
            if(disc[u] <= low[v]) ap[u] = true;
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], disc[v]);
    }
    return subgraphs;
}

int main() {
    scanf("%d%d", &V, &E);
    for(int i=0; i<E; ++i) {
        scanf("%d%d", &A, &B);
        nbr[A].push_back(B);
        nbr[B].push_back(A);
    }
    int cnt = 0;
    for(int n=1; n<=V; ++n) {
        if(!disc[n]) ap[n] = dfs(n, 0) > 1;
        if(ap[n]) ++cnt;
    }
    printf("%d\n", cnt);
    for(int n=1; n<=V; ++n)
        if(ap[n]) printf("%d ", n);
    printf("\n");
}