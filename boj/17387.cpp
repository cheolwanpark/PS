#include <stdio.h>
#include <algorithm>
using namespace std;

typedef pair<long long, long long> V;

int ccw(V a, V b, V c) {
  long long v = (a.first * b.second + b.first * c.second + c.first * a.second) -
                (a.second * b.first + b.second * c.first + c.second * a.first);
  return v == 0 ? 0 : (v > 0 ? 1 : -1);
}

int main() {
  int x1, x2, x3, x4, y1, y2, y3, y4;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  scanf("%d%d%d%d", &x3, &y3, &x4, &y4);
  
  V a={x1, y1}, b={x2, y2}, c={x3, y3}, d={x4, y4};
  
  int abc = ccw(a, b, c), abd = ccw(a, b, d),
      cda = ccw(c, d, a), cdb = ccw(c, d, b);
  if(abc*abd == 0 && cda * cdb == 0) {
    printf("%d\n", min(a, b) <= max(c, d) && min(c, d) <= max(a, b));
  } else {
    printf("%d\n", abc*abd <= 0 && cda*cdb <=0);
  }
}