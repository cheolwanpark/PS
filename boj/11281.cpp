#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 10000, NODEN=(MAXN+1)*2;
int id[NODEN]={0}, scc[NODEN]={0}, counter=1, scc_counter=1, N, M, a, b;
vector<int> edges[NODEN];
stack<int> s;

int pos(int n) {
    if(n > 0) return 2*n;
    else return -2*n+1;
}

int neg(int n) {
    if(n > 0) return 2*n+1;
    else return -2*n;
}

int calcSCC(int node) {
    id[node] = counter++;
    int min_id = id[node];
    s.push(node);
    for(auto next : edges[node]) {
        if(!id[next]) min_id = min(min_id, calcSCC(next));
        else if(!scc[next]) min_id = min(min_id, id[next]);
    }
    if(min_id == id[node]) {
        while(true) {
            auto n = s.top(); s.pop();
            scc[n] = scc_counter;
            if(n == node) break;
        }
        ++scc_counter;
    }
    return min_id;
}

int main() {
    scanf("%d%d", &N, &M);
    while(M--) {
        scanf("%d%d", &a, &b);
        edges[neg(a)].push_back(pos(b));
        edges[neg(b)].push_back(pos(a));
    }
    for(int i=1; i<=N; ++i) {
        if(!id[pos(i)]) calcSCC(pos(i));
        if(!id[neg(i)]) calcSCC(neg(i));
    }
    int valid = 1;
    for(int i=1; i<=N; ++i) {
        if(scc[pos(i)] == scc[neg(i)]) {
            valid = 0;
            break;
        }
    }
    printf("%d\n", valid);
    if(valid) {
        for(int i=1; i<=N; ++i) printf("%d ", scc[neg(i)] > scc[pos(i)] ? 1 : 0);
        printf("\n");
    }
}