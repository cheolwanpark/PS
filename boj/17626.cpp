#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, memo[50001]={0};
    scanf("%d", &N);
    vector<int> s;
    for(int i=1; i*i <= 50000; ++i) s.push_back(i*i);
    for(int i=1; i<=N; ++i) {
        memo[i]=N;
        for(int j=0; j<s.size() && s[j] <= i; ++j) memo[i] = min(memo[i], memo[i-s[j]] + 1);
    }
    printf("%d\n", memo[N]);
}