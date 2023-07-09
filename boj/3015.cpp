#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, h;
    long long r = 0;
    vector<pair<int, int>> s;
    scanf("%d", &N);
    for(int i=0; i<N; ++i) {
        scanf("%d", &h);
        int same_height_count = 1;
        while(!s.empty() && s.back().first <= h) {
            r += s.back().second;
            if(s.back().first == h) same_height_count += s.back().second;
            s.pop_back();
        }
        if(!s.empty()) ++r;
        s.push_back({h, same_height_count});
    }
    printf("%lld\n", r);
}