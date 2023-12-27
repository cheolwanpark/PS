#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> isPrime, visited;
vector<int> S, E, edges[50], inv;

bool dfs(int node) {
    if(visited[node]) return false;
    visited[node] = true;
    for(auto next : edges[node]) {
        if(inv[next] == -1 || dfs(inv[next])) {
            inv[next] = node;
            return true;
        }
    }
    return false;
}

int main() {
    int N, first;
    scanf("%d", &N);
    scanf("%d", &first);
    S.push_back(first);
    for(int i=1, n; i<N; ++i) {
        scanf("%d", &n);
        if(n%2 == first%2) S.push_back(n);
        else E.push_back(n);
    }
    sort(E.begin(), E.end());

    isPrime = vector<bool>(2001, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<=2000; ++i) {
        if(!isPrime[i]) continue;
        for(int j=i+i; j<=2000; j+=i) {
            isPrime[j] = false;
        }
    }

    if(S.size() != E.size()) {
        printf("-1");
        return 0;
    }

    for(int i=0; i<S.size(); ++i) {
        for(int j=0; j<E.size(); ++j) {
            if(isPrime[S[i] + E[j]])
                edges[i].push_back(j);
        }
    }


    bool exist = false;
    visited = vector<bool>(S.size(), false); visited[0] = true;
    inv = vector<int>(E.size(), -1);
    for(auto next : edges[0]) {
        fill(inv.begin(), inv.end(), -1);
        int cnt = 1;
        inv[next] = 0;
        for(int i=1; i<S.size(); ++i) {
            fill(visited.begin()+1, visited.end(), false);
            if(dfs(i)) ++cnt;
        }
        if(cnt == S.size()) {
            exist = true;
            printf("%d ", E[next]);
        }
    }
    if(!exist) printf("-1");
    printf("\n");
}