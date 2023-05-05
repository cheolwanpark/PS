#include <stdio.h>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> block;

int N, M, board[500][500];

vector<block> orig_blocks = {
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 0}},
};

block flipX(block b) {
    int bt=0;
    for(int i=0; i<4; ++i) bt = max(bt, b[i].first);
    for(int i=0; i<4; ++i) b[i].first = bt - b[i].first;
    return b;
}

block flipY(block b) {
    int r=0;
    for(int i=0; i<4; ++i) r = max(r, b[i].second);
    for(int i=0; i<4; ++i) b[i].second = r - b[i].second;
    return b;
}

bool isValid(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}
int score(int y, int x, block &b) {
    int r = 0;
    for(int i=0; i<4; ++i) {
        auto [dy, dx] = b[i];
        if(!isValid(y+dy, x+dx)) return 0;
        r += board[y+dy][x+dx];
    }
    return r;
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) scanf("%d", &board[i][j]);
    }
    
    vector<block> blocks;
    for(auto block : orig_blocks) {
        blocks.push_back(block);
        blocks.push_back(flipX(block));
        blocks.push_back(flipY(block));
    }

    int r = 0;
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            for(auto block : blocks) {
                r = max(r, score(i, j, block));
            }
        }
    }
    printf("%d\n", r);
}