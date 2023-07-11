#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAXN = 20, NODEN=(MAXN+1)*2;
int N, M, a, b, scc[NODEN]={0}, id[NODEN]={0}, counter=1;
vector<int> edges[NODEN];
stack<int> s;

int toNode(int p) {
    if(p > 0) return p*2;
    else return -p*2+1;
}

int not_(int node_idx) {
    if(node_idx&1) return node_idx - 1;
    else return node_idx + 1;
}

int calcSCC(int node) {
    id[node] = counter++;
    s.push(node);
    int min_id = id[node];
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
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; ++i) {
        scanf("%d%d", &a, &b);
        a = toNode(a);
        b = toNode(b);
        edges[not_(a)].push_back(b);
        edges[not_(b)].push_back(a);
    }
    for(int i=1; i<=N; ++i) {
        int n = toNode(i);
        if(!id[n]) calcSCC(n);
        if(!id[not_(n)]) calcSCC(not_(n));
    }
    int valid = 1;
    for(int i=1; i<=N; ++i) {
        int n = toNode(i);
        if(scc[n] == scc[not_(n)]) {
            valid = 0;
            break;
        }
    }
    printf("%d\n", valid);
}