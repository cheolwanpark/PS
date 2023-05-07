#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

int N, m[20][20];
int d[20][20];

bool isValid(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N;
}
void pushIfValid(queue<ii> &q, int i, int j, int c, int size) {
    if(isValid(i, j) && m[i][j] <= size && d[i][j] < 0) {
        q.push({i, j});
        d[i][j] = c;
    }
}
tuple<int, int, int> getFish(ii p, int size) {
    queue<ii> q;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) d[i][j] = -1;
    }
    q.push(p); 
    d[p.first][p.second] = 0;

    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        auto c = d[i][j];
        pushIfValid(q, i-1, j, c+1, size);
        pushIfValid(q, i, j-1, c+1, size);
        pushIfValid(q, i+1, j, c+1, size);
        pushIfValid(q, i, j+1, c+1, size);
    }

    ii np = p;
    int min_d = 401;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            if(d[i][j] != -1 && d[i][j] < min_d && 0 < m[i][j] && m[i][j] < size) {
                np = {i, j};
                min_d = d[i][j];
            }
        }
    }
    return {np.first, np.second, min_d == 401 ? -1 : min_d};
}

int main() {
    ii p;
    int size = 2;
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
            scanf("%d", &m[i][j]);
            if(m[i][j] == 9) {
                p={i, j};
                m[i][j] = 0;
            }
        }
    }

    int r=0, take=0;
    while(true) {
        auto [i, j, dist] = getFish(p, size);
        if(dist < 0) break;
        
        r += dist;
        p = {i, j};
        m[i][j] = 0;
        take++;
        if(take == size) {
            size++;
            take = 0;
        }
    }
    printf("%d\n", r);
}