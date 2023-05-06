#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int s[4000001]={0};
int find(int i) {
    if(s[i] == i) return s[i];
    else return s[i] = find(s[i]);
}
void uni(int c, int p) {
    s[c] = s[p];
}

int main() {
    int N, M, K, n;
    vector<int> card;
    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<M; ++i) {
        scanf("%d", &n);
        card.push_back(n);
        s[i] = i;
    }
    sort(card.begin(), card.end());
    for(int i=0; i<K; ++i) {
        scanf("%d", &n);
        auto iter = upper_bound(card.begin(), card.end(), n);
        auto idx = find(iter - card.begin());
        printf("%d\n", card[idx]);
        uni(idx, idx+1);
    }
}