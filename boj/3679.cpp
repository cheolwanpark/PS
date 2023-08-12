#include <stdio.h>
#include <algorithm>
using namespace std;

struct Point { 
    int x; int y; int i;
    bool operator < (const Point &rhs) const {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
};

int C, N;
Point P[2000];

int ccw(Point a, Point b, Point c) {
    auto res = a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
    if(res > 0) return 1;
    else if(res < 0) return -1;
    else return 0;
}

int sqr_distance(Point a, Point b) {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx*dx + dy*dy;
}

int main() {
    scanf("%d", &C);
    while(C--) {
        scanf("%d", &N);
        for(int i=0; i<N; ++i) {
            scanf("%d%d", &P[i].x, &P[i].y);
            P[i].i = i;
        }
        swap(P[0], *min_element(P, P+N));
        sort(P+1, P+N, [](Point a, Point b) {
            auto ccw_v = ccw(P[0], a, b);
            if(ccw_v) return ccw_v > 0;
            else return sqr_distance(P[0], a) < sqr_distance(P[0], b);
        });
        int last_part_beg_idx = N-1;
        for(;last_part_beg_idx >= 1; --last_part_beg_idx) {
            if(ccw(P[0], P[last_part_beg_idx], P[last_part_beg_idx-1]) != 0) break;
        }
        reverse(P+last_part_beg_idx, P+N);
        for(int i=0; i<N; ++i) printf("%d ", P[i].i);
        printf("\n");
    }
}