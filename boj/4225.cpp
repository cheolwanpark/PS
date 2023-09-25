#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct Point {int x; int y;};
int N, x, y;

int ccw(Point a, Point b, Point c) {
    int z = a.x*b.y+b.x*c.y+c.x*a.y - a.y*b.x-b.y*c.x-c.y*a.x;
    return z ? (z > 0 ? 1 : -1) : 0;
}

int sqr_len(Point a, Point b) {
    int dx = b.x - a.x, dy = b.y - a.y;
    return dx*dx + dy*dy;
}

int main() {
    int C = 0;
    while(true) {
        scanf("%d", &N);
        if(!N) break;
        vector<Point> poly(N), hull;
        for(int i=0; i<N; ++i) {
            scanf("%d%d", &poly[i].x, &poly[i].y);
            if((poly[i].y < poly[0].y) || (poly[i].y == poly[0].y && poly[i].x < poly[0].x)) swap(poly[i], poly[0]);
        }
        sort(poly.begin()+1, poly.end(), [&](Point &a, Point &b) {
            int det = ccw(poly[0], a, b);
            return det ? det > 0 : sqr_len(poly[0], a) < sqr_len(poly[0], b);
        });
        for(int i=0; i<poly.size();) {
            if(hull.size() < 2) hull.push_back(poly[i++]);
            else if(ccw(hull[hull.size()-2], hull.back(), poly[i]) > 0) hull.push_back(poly[i++]);
            else hull.pop_back();
        }

        double r = -1;
        for(int i=0; i<hull.size(); ++i) {
            double max_dist = 0;
            Point a = hull[i], b = hull[(i+1)%hull.size()];
            for(auto c : hull) {
                int A = b.y - a.y, B = a.x - b.x, C = a.y*b.x - a.x*b.y;
                double dist = abs(A*c.x + B*c.y + C) / sqrt(A*A+B*B);
                max_dist = max(max_dist, dist);
            }
            if(r < 0) r = max_dist;
            else r = min(r, max_dist);
        }
        printf("Case %d: %.2f\n", ++C, ceil(r*100)/100.0);
    }
}