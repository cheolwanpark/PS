#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

typedef pair<int, int> ii;
int N, M, m[8][8], vst[8][8];

int count(int i, int j) {
    if(i < 0 || i >= N || j < 0 || j >= M || m[i][j] == 1 || vst[i][j]) return 0;
    vst[i][j] = 1;
    return 1 + count(i-1, j) + count(i+1, j) + count(i, j-1) + count(i, j+1);
}

vector<ii> f2p(vector<int> &flag) {
    vector<ii> r;
    for(int i=0; i<flag.size(); ++i) {
        if(flag[i]) r.push_back({i/M, i%M});
    }
    return r;
}

int valid(vector<ii> &P) {
    for(auto p : P) {
        auto [i, j] = p;
        if(m[i][j] != 0) return false;
    }
    return true;
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) scanf("%d", &m[i][j]);
    }
    vector<int> flag(N*M);
    fill(flag.end() - 3, flag.end(), true);
    int r = 0;
    do {
        auto P = f2p(flag);
        if(!valid(P)) continue;
        for(auto p : P) m[p.first][p.second] = 1;
        int n=N*M;
        memset(vst, 0, sizeof(vst));
        for(int i=0; i<N; ++i) {
            for(int j=0; j<M; ++j) {
                if(!vst[i][j] && m[i][j] == 2) n -= count(i, j);
                else if(m[i][j] == 1) n--;
            }
        }
        r = max(r, n);
        for(auto p : P) m[p.first][p.second] = 0;
    } while(next_permutation(flag.begin(), flag.end()));
    printf("%d\n", r);
}