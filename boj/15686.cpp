#include <stdio.h>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int main() {
    int N, M, b;
    vector<pair<int, int>> home, store;
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=N; ++j) {
            scanf("%d", &b);
            if(b == 1) home.push_back({i, j});
            else if(b == 2) store.push_back({i, j});
        }
    }

    vector<int> flag(store.size());
    fill(flag.end() - M, flag.end(), true);
    int r = INF;
    do {
        int cost = 0;
        for(auto h : home) {
            auto [hi, hj] = h;
            int d = INF;
            for(int i=0; i<flag.size(); ++i) {
                if(flag[i]) {
                    auto [si, sj] = store[i];
                    d = min(d, abs(si - hi) + abs(sj - hj));
                }
            }
            cost += d;
        }
        r = min(r, cost);
    } while(next_permutation(flag.begin(), flag.end()));
    printf("%d\n", r);
}