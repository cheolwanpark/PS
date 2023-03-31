// https://www.acmicpc.net/problem/1202
#include <stdio.h>
#include <algorithm>
using namespace std;

struct Jewel {
    int m;
    int v;
};

bool cmp(const Jewel &a, const Jewel &b) {
    return a.v == b.v ? a.m > b.m : a.v < b.v;
}

int main() {
    int N, K;
    Jewel j[300000];
    int c[300000];

    scanf("%d%d", &N, &K);
    for(int i=0; i<N; ++i) scanf("%d%d", &j[i].m, &j[i].v);
    for(int i=0; i<K; ++i) scanf("%d", c+i);
    // sort(j, j+N, cmp);
    // sort(c, c+N);
    for(int i=0; i<N; ++i) printf("%d %d\n", j[i].m, j[i].v);
}