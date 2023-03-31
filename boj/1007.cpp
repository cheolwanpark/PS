// https://www.acmicpc.net/problem/1007
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

typedef pair<long long, long long> V;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N;
        V p[21], s = {0, 0};
        scanf("%d", &N);
        for(int i=0; i<N; ++i) {
            scanf("%lld%lld", &p[i].first, &p[i].second);
            s.first += p[i].first;
            s.second += p[i].second;
        }

        vector<bool> v(N);
        fill(v.end() - N/2, v.end(), true);
        long long minSqr = -1;
        do {
            V tmp = s;
            for(int i=0; i<N; ++i) {
                if(v[i]) {
                    tmp.first -= 2 * p[i].first;
                    tmp.second -= 2 * p[i].second;
                }
            }
            auto sqr = tmp.first*tmp.first + tmp.second*tmp.second;
            if(minSqr < 0 || sqr < minSqr) {
                minSqr = sqr;
            }
        } while(next_permutation(v.begin(), v.end()));
        printf("%.10lf\n", sqrt(minSqr));
    }
}