#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

struct Shark {
    int r, c, s, d, z;
};

int R, C, M;
vector<Shark> sharks;
vector<bool> alive;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int memo[100][100];

Shark next(Shark &shark) {
    auto [r, c, s, d, z] = shark;
    auto len = d < 2 ? R : C;
    auto S = s%((len-2)*2 + 2);
    while(S > 0) {
        if(d < 2) {
            int tgt = d == 0 ? 0 : R-1;
            int delta = abs(tgt - r);
            if(delta <= S) {
                r = tgt;
                S -= delta;
                d = d == 0 ? 1 : 0;
            } else {
                r += dir[d][0] * S;
                break;
            }
        } else {
            int tgt = d == 2 ? C-1 : 0;
            int delta = abs(tgt - c);
            if(delta <= S) {
                c = tgt;
                S -= delta;
                d = d == 2 ? 3 : 2;
            } else {
                c += dir[d][1] * S;
                break;
            }
        }
    }
    return {r, c, s, d, z};
}

int main() {
    memset(memo, -1, sizeof(memo));
    scanf("%d%d%d", &R, &C, &M);
    for(int i=0; i<M; ++i) {
        int r, c, s, d, z;
        scanf("%d%d%d%d%d", &r, &c, &s, &d, &z);
        sharks.push_back({r-1, c-1, s, d-1, z});
        alive.push_back(true);
        memo[r-1][c-1] = i;
    }

    int res = 0;
    for(int col=0; col<C; ++col) {
        for(int r=0; r<R; ++r) {
            if(memo[r][col] != -1) {
                auto idx = memo[r][col];
                res += sharks[idx].z;
                alive[idx] = false;
                break;
            } 
        }

        memset(memo, -1, sizeof(memo));
        for(int i=0; i<sharks.size(); ++i) {
            if(!alive[i]) continue;
            auto shark = sharks[i];
            auto [r, c, s, d, z] = next(shark);
            if(memo[r][c] < 0) {
                memo[r][c] = i;
            } else {
                auto &other = sharks[memo[r][c]];
                if(shark.z > other.z) {
                    alive[memo[r][c]] = false;
                    memo[r][c] = i;
                } else {
                    alive[i] = false;
                }
            }
            sharks[i] = {r, c, s, d, z};
        }

    }
    printf("%d\n", res);
}