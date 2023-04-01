#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
  int x, y, w, h;
  scanf("%d%d%d%d", &x, &y, &w, &h);
  printf("%d\n", min(x, min(y, min(abs(w - x), abs(h - y)))));
}