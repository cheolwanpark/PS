#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int V, E, A, B;
vector<int> edges[10001];
int id[10001]={0}, complete[10001]={0}, counter=1;
stack<int> stk;
vector<pair<int, vector<int>>> scc;

int dfs(int node) {
    id[node] = counter++;
    int min_id = id[node];
    stk.push(node);
    for(auto next : edges[node]) {
        if(!id[next]) min_id = min(min_id, dfs(next));
        else if(!complete[next]) min_id = min(min_id, id[next]);
    }
    if(min_id == id[node]) {
        vector<int> v;
        while(true) {
            auto elem = stk.top(); stk.pop();
            v.push_back(elem);
            complete[elem] = 1;
            if(elem == node) break;
        }
        sort(v.begin(), v.end());
        scc.push_back({v[0], v});
    }
    return min_id;
}

int main() {
    scanf("%d%d", &V, &E);
    for(int i=0; i<E; ++i) {
        scanf("%d%d", &A, &B);
        edges[A].push_back(B);
    }
    for(int i=1; i<=V; ++i) {
        if(!id[i]) dfs(i);
    }
    sort(scc.begin(), scc.end());
    printf("%lu\n", scc.size());
    for(auto elems : scc) {
        for(auto elem : elems.second) printf("%d ", elem);
        printf("-1\n");
    }
}