#include <stdio.h>
#include <algorithm>
using namespace std;

int N, M;
char m[1000][1001];
int memo[1000000];

int toIdx(int i, int j) {
    return i*M+j;
}
int find(int idx) {
    if(memo[idx] == idx) return idx;
    else return memo[idx] = find(memo[idx]);
}
void uni(int pa, int ch) {
    if(find(pa) != find(ch)) memo[ch] = memo[pa];
}

bool isValid(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M;
}
pair<int, int> movedPos(int i, int j) {
    pair<int, int> r;
    if(m[i][j] == 'U') r = {i-1, j};
    else if(m[i][j] == 'D') r = {i+1, j};
    else if(m[i][j] == 'L') r = {i, j-1};
    else if(m[i][j] == 'R') r = {i, j+1};
    if(isValid(r.first, r.second)) return r;
    else return {i, j};
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; ++i) scanf("%s", m[i]);
    for(int i=0; i<N*M; ++i) memo[i] = i;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            auto [ni, nj] = movedPos(i, j);
            auto ch = toIdx(i, j);
            auto pa = toIdx(ni, nj);
            uni(pa, ch);
        }
    }

    int r = 0;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            auto idx = toIdx(i, j);
            if(find(idx) == idx) r++;
        }
    }
    printf("%d\n", r);
}