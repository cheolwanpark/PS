#include <stdio.h>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dist(string &a, string &b) {
    int r = 0;
    for(int i=0; i<4; ++i) {
        r += a[i] == b[i] ? 0 : 1;
    }
    return r;
}

int main() {
    int T, N, r;
    char in[5];
    scanf("%d", &T);
    while(T--) {
        multiset<string> s;
        scanf("%d", &N);
        for(int i=0; i<N; ++i) {
            scanf("%s", in);
            string tmp(in);
            if(s.count(tmp) < 3) s.insert(tmp);
        }
        vector<string> v(s.begin(), s.end());
        r=12;
        for(int i=0; i<v.size(); ++i) {
            for(int j=i+1; j<v.size(); ++j) {
                for(int k=j+1; k<v.size(); ++k) {
                    r = min(r, dist(v[i], v[j]) + dist(v[i], v[k]) + dist(v[j], v[k]));
                }
            }
        }
        printf("%d\n", r);
    }
}