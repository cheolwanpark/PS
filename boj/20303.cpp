#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K, a, b, n[30001], uf[30001], gid[30001], memo[3001][30001]={0};
vector<pair<int, int>> grp={{0, 0}};

int find(int i) {
    if(uf[i] == i) return i;
    else return uf[i] = find(uf[i]);
}

void uni(int i, int j) {
    i = find(i);
    j = find(j);
    uf[max(i, j)] = min(i, j);
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for(int i=1; i<=N; ++i) {
        scanf("%d", n+i);
        uf[i] = i;
    }
    for(int i=0; i<M; ++i) {
        scanf("%d%d", &a, &b);
        uni(a, b);
    }
    for(int i=1, j=1; i<=N; ++i) {
        if(i == find(i)) {
            grp.push_back({1, n[i]});
            gid[i] = j++;
        } else {
            auto id = gid[find(i)];
            grp[id].first++;
            grp[id].second += n[i];
        }
    }
    for(int W=1; W<K; ++W) {
        for(int i=1; i<grp.size(); ++i) {
            auto [w, v] = grp[i];
            if(w > W) memo[W][i] = memo[W][i-1];
            else memo[W][i] = max(memo[W][i-1], memo[W-w][i-1] + v);
        }
    }
    printf("%d\n", memo[K-1][grp.size()-1]);
}