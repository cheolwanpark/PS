// https://www.acmicpc.net/problem/2579https://www.acmicpc.net/problem/2579
#include <stdio.h>
#include <algorithm>
using namespace std;

int memo1[301];
int memo2[301];
int score[301];
int N;

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; ++i) {
        scanf("%d", score + i);
        memo1[i] = memo2[i] = -1;
    }
    
    memo1[1] = score[1];
    memo2[1] = score[1];
    if(N > 1) {
        memo1[2] = memo1[1] + score[2];
        memo2[2] = score[2];
    }
    for(int i=3; i<=N; ++i) {
        int onestep = memo2[i-1] + score[i];
        int twostep = max(memo1[i-2], memo2[i-2]) + score[i];
        memo1[i] = onestep;
        memo2[i] = twostep;
    }
    printf("%d\n", max(memo1[N], memo2[N]));
}