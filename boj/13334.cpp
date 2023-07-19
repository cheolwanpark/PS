#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using ii = pair<int, int>;
int N, D, a, b, r=0;
ii v[100000];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        scanf("%d%d", &a, &b);
        v[i] = {min(a, b), max(a, b)};
    }
    scanf("%d", &D);
    sort(v, v+N, [](ii &a, ii &b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });
    for(int i=0; i<N; ++i) {
        pq.push(v[i].first);
        while(!pq.empty() && v[i].second - pq.top() > D) pq.pop();
        r = max(r, (int)pq.size());
    }
    printf("%d\n", r);
}