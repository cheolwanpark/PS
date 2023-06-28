#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct P {int x; int y;};

int ccw(P p1, P p2, P p3) {
    long long ccw = 1LL*(p2.x - p1.x)*(p3.y - p2.y) - 1LL*(p3.x - p2.x)*(p2.y - p1.y);
    return ccw == 0 ? 0 : (ccw > 0 ? 1 : -1);
}

int main() {
    int N, x, y;
    vector<P> p, r;
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        scanf("%d%d", &x, &y);
        p.push_back({x, y});
        if(y < p[0].y || (y == p[0].y && x < p[0].x)) swap(p[0], p[i]);
    }
    sort(p.begin() + 1, p.end(), [&](P a, P b) {
        int ccw_val = ccw(p[0], a, b);
        if(ccw_val != 0) return ccw_val > 0;
        return a.y < b.y || (a.y == b.y && a.x < b.x);
    });

    r.push_back(p[0]); r.push_back(p[1]);
    for(int i=2; i<N; ++i) {
        while(r.size() >= 2 && ccw(r[r.size() - 2], r[r.size() - 1], p[i]) <= 0) r.pop_back();
        r.push_back(p[i]);
    }
    printf("%ld\n", r.size());
}