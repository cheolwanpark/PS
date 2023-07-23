#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

using ii = pair<int, int>;
const int N=5;
ii deltas[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char board[N][N+1], visit[N][N];

int getState() {
    int r = 0;
    for(int i=0, y, x; i<N*N; ++i) {
        y = i/N; x = i%N;
        if(board[y][x] == '*') r |= 1 << i;
    }
    return r;
}

int getState(const vector<ii> &pieces) {
    int r = 0;
    for(auto piece : pieces) {
        auto [y, x] = piece;
        r |= 1 << (y*N+x);
    }
    return r;
}

vector<ii> getPieces(int state) {
    vector<ii> r;
    for(int i=0; i<N*N; ++i) {
        if(state & (1<<i)) r.emplace_back(i/N, i%N);
    }
    return r;
}

bool exist(int y, int x, const vector<ii> &pieces) {
    for(auto piece : pieces) {
        auto [py, px] = piece;
        if(y == py && x == px) return true;
    }
    return false;
}

bool valid(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

int countConnectedPieces(int y, int x, const vector<ii> &pieces) {
    visit[y][x] = 1;
    if(!exist(y, x, pieces)) return 0;
    int r=1;
    for(auto delta : deltas) {
        auto [ny, nx] = delta;
        ny += y; nx += x;
        if(valid(ny, nx) && !visit[ny][nx]) r += countConnectedPieces(ny, nx, pieces);
    }
    return r;
}
bool isComplete(const vector<ii> &pieces) {
    memset(visit, 0, sizeof(visit));
    auto [y, x] = pieces[0];
    return countConnectedPieces(y, x, pieces) == pieces.size();
}

int main() {
    for(int i=0; i<N; ++i) scanf("%s", board[i]);
    queue<ii> q;
    unordered_set<int> visit;
    q.push({getState(), 0}); visit.insert(q.front().first);

    while(!q.empty()) {
        auto [state, moves] = q.front(); q.pop();
        auto pieces = getPieces(state);
        if(isComplete(pieces)) {
            printf("%d\n", moves);
            break;
        }

        for(int i=0; i<pieces.size(); ++i) {
            auto [y, x] = pieces[i];
            for(auto delta : deltas) {
                auto [ny, nx] = delta;
                ny += y; nx += x;
                if(valid(ny, nx)) {
                    pieces[i] = {ny, nx};
                    auto state = getState(pieces);
                    pieces[i] = {y, x};
                    if(visit.find(state) != visit.end() || exist(ny, nx, pieces)) continue;
                    q.push({state, moves+1});
                    visit.insert(state);
                }
            }
        }
    }
}