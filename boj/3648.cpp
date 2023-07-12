#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1000, NODEN=(MAXN+1)*2;
int id[NODEN]={0}, scc[NODEN]={0}, counter, N, M, a, b;
vector<int> edges[NODEN];
stack<int> s;

void reset() {
    memset(id, 0, sizeof(id));
    memset(scc, 0, sizeof(scc));
    counter = 1;
    for(int i=0; i<NODEN; ++i) edges[i].clear();
    while(!s.empty()) s.pop();
}

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
            scc[n] = node;
            if(n == node) break;
        }
    }
    return min_id;
}

int main() {
    while(scanf("%d%d", &N, &M) != EOF) {
        reset();
        while(M--) {
            scanf("%d%d", &a, &b);
            edges[neg(a)].push_back(pos(b));
            edges[neg(b)].push_back(pos(a));
        }
        edges[neg(1)].push_back(pos(1));
        for(int i=1; i<=N; ++i) {
            if(!id[pos(i)]) calcSCC(pos(i));
            if(!id[neg(i)]) calcSCC(neg(i));
        }
        int valid = true;
        for(int i=1; i<=N; ++i) {
            if(scc[pos(i)] == scc[neg(i)]) {
                valid = false;
                break;
            }
        }
        printf("%s\n", valid ? "yes" : "no");
    }
}